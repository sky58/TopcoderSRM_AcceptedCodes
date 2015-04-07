//SRM278DIV1-1000 UnitsMoving
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
double sx[55],sy[55],v[55],gx[55],gy[55];
const int maxv = 5100;
 
struct e_t { int to, cap, rev; };
 
int V, S, T;
vector<e_t> adj[maxv];
 
int rej[maxv];
int red[maxv];
 
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

class UnitsMoving{
	public:
	double UnitsMoving::bestTime(vector <string> s,vector <string> g){
		int i,j,k,n=s.size();
		for(i=0;i<n;i++){
			istringstream sin(s[i]);sin>>sx[i]>>sy[i]>>v[i];
			istringstream si(g[i]);si>>gx[i]>>gy[i];
		}
		double x=0.0,y=1e10;V=2*n+2;S=2*n;T=2*n+1;
		for(i=0;i<100;i++){
			for(j=0;j<V;j++) adj[j].clear();double z=(x+y)/2;
			for(j=0;j<n;j++) for(k=0;k<n;k++){
				if(sqrt((sx[j]-gx[k])*(sx[j]-gx[k])+(sy[j]-gy[k])*(sy[j]-gy[k]))<=z*v[j]) aedge(j,n+k,1);
			}
			for(j=0;j<n;j++){aedge(2*n,j,1);aedge(n+j,2*n+1,1);}
			if(mflow()<n) x=z;else y=z;
		}
		return (x+y)/2;
	}
};
