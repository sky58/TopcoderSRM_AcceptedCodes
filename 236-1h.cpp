//SRM236DIV1-1000 Parking
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int di[110][110];bool sumi[55][55];int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
map<pint,int> par;vector <pint> now,next,cl,c;
const int maxv = 5100;
 
struct e_t { int to, cap, rev; };
 
int V, S, T;
vector<e_t> adj[maxv];
 
int rej[maxv];
int red[maxv];
void aedg(int x,int y){
	if(!sumi[x][y]){sumi[x][y]=true;next.pb(mp(x,y));}return;
}
void aedge(int i, int j, int c) {
  adj[i].pb((e_t){j, c, adj[j].size() + (i == j ? 1 : 0)});
  adj[j].pb((e_t){i, 0, adj[i].size() - 1});
}
 
void bfs() {
  memset(rej, -1, sizeof(rej));
  queue<int> q;
  rej[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < (int)adj[v].size(); i++) {
      e_t &e = adj[v][i];
      if (e.cap <= 0) continue;
      if (rej[e.to] != -1) continue;
      q.push(e.to);
      rej[e.to] = rej[v] + 1;
    }
  }
}
 
int dfs(int v, int flow) {
  if (v == T || flow == 0) return flow;
  for (; red[v] < (int)adj[v].size(); red[v]++) {
    e_t &e = adj[v][red[v]];
    if (rej[e.to] <= rej[v]) continue;
    int f = dfs(e.to, min(flow, e.cap));
    if (f > 0) {
      e.cap -= f;
      adj[e.to][e.rev].cap += f;
      return f;
    }
  }
  return 0;
}
 
int mflow() {
  int total = 0, fsum, f;
  do {
    bfs();
    memset(red, 0, sizeof(red));
    fsum = 0;
    while (0 < (f = dfs(S, INT_MAX))) fsum += f;
    total += fsum;
  } while (fsum > 0);
  return total;
}
class Parking{
	public:
	int Parking::minTime(vector <string> a){
		int h=a.size(),w=a[0].size(),n=0,m=0,lo=0,hi=10000,i,j,k,l;
		for(i=0;i<110;i++) for(j=0;j<110;j++) di[i][j]=11000;
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(a[i][j]=='C'){n++;c.pb(mp(i,j));}
			if(a[i][j]=='P'){par[mp(i,j)]=m;m++;}
		}
		for(i=0;i<n;i++){
			memset(sumi,false,sizeof(sumi));aedg(c[i].fi,c[i].se);now=next;next=cl;
			for(j=0;now.size()>0;j++){
			 for(l=0;l<now.size();l++){
				int x=now[l].fi,y=now[l].se;//cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
				for(k=0;k<4;k++){
					int nx=x+dx[k],ny=y+dy[k];
					if(nx>=0 && nx<h && ny>=0 && ny<w){
						if(a[nx][ny]=='P') di[i][par[mp(nx,ny)]]<?=j+1;
//						if(a[nx][ny]=='C' || a[nx][ny]=='.') aedg(nx,ny);
						if(a[nx][ny]!='X') aedg(nx,ny);
					}
				}
			 }
			 now=next;next=cl;
			}
		}
//		cout<<par[mp(1,6)]<<endl;
//		for(i=0;i<n;i++) for(j=0;j<m;j++) cout<<i<<' '<<j<<' '<<di[i][j]<<endl;
		V=n+m+2;S=n+m;T=n+m+1;
		while(hi>lo){
			int mi=(hi+lo)/2;
			for(i=0;i<V;i++) adj[i].clear();
			for(i=0;i<n;i++) aedge(S,i,1);
			for(i=0;i<m;i++) aedge(i+n,T,1);
			for(i=0;i<n;i++) for(j=0;j<m;j++){if(di[i][j]<=mi) aedge(i,j+n,1);}
			if(mflow()>=n) hi=mi;else lo=mi+1;
		}
		if(hi>=10000) return -1;return hi;
	}
};
