//SRM422DIV1-1000 WorkersOnPlane
#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;

#define all(c) (c).begin(), (c).end() 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair
 
const int MAX_V = 5100;
 
struct e_t { int to, cap, rev; };
 
int V, S, T;
vector<e_t> adj[MAX_V];
 
int level[MAX_V];
int done[MAX_V];
 
void add_edge(int i, int j, int c) {
  adj[i].push_back((e_t){j, c, adj[j].size() + (i == j ? 1 : 0)});
  adj[j].push_back((e_t){i, 0, adj[i].size() - 1});
}
 
void levelize() {
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[S] = 0;
  que.push(S);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < (int)adj[v].size(); i++) {
      e_t &e = adj[v][i];
      if (e.cap <= 0) continue;
      if (level[e.to] != -1) continue;
      que.push(e.to);
      level[e.to] = level[v] + 1;
    }
  }
}
 
int augment(int v, int flow) {
  if (v == T || flow == 0) return flow;
  for (; done[v] < (int)adj[v].size(); done[v]++) {
    e_t &e = adj[v][done[v]];
    if (level[e.to] <= level[v]) continue;
    int f = augment(e.to, min(flow, e.cap));
    if (f > 0) {
      e.cap -= f;
      adj[e.to][e.rev].cap += f;
      return f;
    }
  }
  return 0;
}

int max_flow() {
  int total = 0, fsum, f;
  do {
    levelize();
    memset(done, 0, sizeof(done));
    fsum = 0;
    while (0 < (f = augment(S, INT_MAX))) fsum += f;
    total += fsum;
  } while (fsum > 0);
  return total;
}

class WorkersOnPlane{
	public:
	int WorkersOnPlane::howMany(vector <string> a,int b){
		int n=a.size(),m=a[0].size(),v=m*n,i,j,k,l;
		int dx[4]={1,-1,0,0};int dy[4]={0,0,1,-1};
		vector <int> w;bool sumi[1000];
		V=v*2+2;S=v*2;T=v*2+1;
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='W'){w.pb(i*m+j);add_edge(i*m+j,v+i*m+j,1);}
			if(a[i][j]=='G') add_edge(S,i*m+j,1);
			if(a[i][j]=='S') add_edge(i*m+j,T,1);
		}
		for(i=0;i<w.size();i++){
			memset(sumi,false,sizeof(sumi));
			vector <int> now,next;
			now.pb(w[i]);sumi[w[i]]=true;
			for(j=0;j<=b;j++){
				for(k=0;k<now.size();k++){
					int x=now[k]/m,y=now[k]%m;
//					cout<<j<<' '<<x<<' '<<y<<' '<<'\n';
					if(a[x][y]=='G') add_edge(x*m+y,w[i],1);
					if(a[x][y]=='S') add_edge(w[i]+v,x*m+y,1);
					if(a[x][y]=='.' || x*m+y==w[i]){
						for(l=0;l<4;l++){
							int nx=x+dx[l],ny=y+dy[l];
							if(nx>=0 && ny>=0 && nx<n && ny<m) if(!sumi[nx*m+ny]){next.pb(nx*m+ny);sumi[nx*m+ny]=true;}
						}
					}
				}
				now=next;next.clear();
			}
		}
		return max_flow();
	}
};
