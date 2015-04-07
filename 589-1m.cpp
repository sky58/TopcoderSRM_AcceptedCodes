//SRM589DIV1-450 GearsDiv1
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
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
    while (0 < (f = dfs(S, 100000000))) fsum += f;
    total += fsum;
  } while (fsum > 0);
  return total;
}
int cal(char x,char y,string a,vector <string> b){
	int n=a.size();
	S=n;T=S+1;V=T+1;
	rep(i,maxv) adj[i].clear();
	rep(i,n){
		if(a[i]==x) aedge(S,i,1);
		if(a[i]==y) aedge(i,T,1);
	}
	rep(i,n) rep(j,n){
		if(a[i]==x && a[j]==y && b[i][j]=='Y') aedge(i,j,1);
	}
	return mflow();
}
class GearsDiv1{
	public:
	int getmin(string a,vector <string> b){
		return min(cal('R','G',a,b),min(cal('R','B',a,b),cal('B','G',a,b)));
	}
};
