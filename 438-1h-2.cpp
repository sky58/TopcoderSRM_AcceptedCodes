//SRM438DIV1-1000 FeudaliasWar(var2)
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
 
const int MAX_V = 2600;
 
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

class FeudaliasWar{
	public:
	double FeudaliasWar::getMinimumTime(vector <int> sx,vector <int> sy,vector <int> bx,vector <int> by,int a,int b,int c){
		int n=bx.size(),m=sx.size(),i,j,k,l;
		double x=0.0,y=10e10,f=(double)(a+b*60)/60,g=(double)a/60;
		double dist[60][60];
		S=n*m+m;T=n*m+m+1;V=n*m+m+2;
		for(i=0;i<n;i++) for(j=0;j<m;j++) dist[i][j]=sqrt((double)(bx[i]-sx[j])*(bx[i]-sx[j])+(double)(by[i]-sy[j])*(by[i]-sy[j]));
		for(i=0;i<70;i++){
			double z=(x+y)/2;//MaxFlow mf(n*m+m+2);
			for(j=0;j<V;j++) adj[j].clear();
			for(j=0;j<m*n;j++) add_edge(n*m+m,j,1);
			for(j=0;j<m;j++) add_edge(n*m+j,n*m+m+1,1);
			for(j=0;j<n;j++) for(k=0;k<m;k++) for(l=0;l<m;l++){
				if(dist[j][k]<(z-f*l-g)*c+10e-12){
					add_edge(j*m+l,n*m+k,1);//printf("%f\n%d %d %d\n",z,j,k,l);
				}
			}
//			cout<<mf.maxflow(n*m+m,n*m+m+1);
			if(max_flow()==m) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
