//SRM360DIV1-500 PrinceOfpersia
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
class PrinceOfPersia{
	public:
	int PrinceOfPersia::minObstacles(vector <string> a){
		int i,j,n=a.size(),m=a[0].size(),f=0,k,v=m*n;
		int dx[4]={0,0,1,-1};int dy[4]={1,-1,0,0};
		V=v*2+2;S=v*2;T=v*2+1;
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='P'){
				if(f==0){f=1;add_edge(S,i*m+j,500);}
				else add_edge(i*m+j+v,T,500);
				add_edge(i*m+j,i*m+j+v,500);
			}
			if(a[i][j]=='.') add_edge(i*m+j,i*m+j+v,1);
			for(k=0;k<4;k++){
				int x=dx[k]+i,y=dy[k]+j;
				if(x<0 || x>=n || y<0 || y>=m) continue;
				add_edge(i*m+j+v,x*m+y,500);
			}
		}
		int out=max_flow();
		if(out>100) return -1;return out;
	}
};
