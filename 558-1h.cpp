//SRM558DIV1-1000 SurroundingGame
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
#define REP(i,a,b) for(i=a;i<b;i++)
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
    while (0 < (f = dfs(S, INT_MAX))) fsum += f;
    total += fsum;
  } while (fsum > 0);
  return total;
}
int dec(char a){
	if(a<='9' && a>='0') return (a-'0');
	if(a<='z' && a>='a') return (a-'a')+10;
	if(a<='Z' && a>='A') return (a-'A')+36;
}
class SurroundingGame{
	public:
	int SurroundingGame::maxScore(vector <string> c,vector <string> b){
		int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
		int n=c.size(),m=c[0].size(),sum=0,i,j,k,inf=1000000;
		S=n*m*2;T=S+1;V=T+1;
		rep(i,n) rep(j,m){
			sum+=dec(b[i][j]);
			//white
			if((i+j)%2==0){
				aedge(n*m+i*m+j,T,dec(b[i][j]));
				aedge(i*m+j,n*m+i*m+j,inf);
				int t=(dec(b[i][j])-dec(c[i][j]));
				if(t<0) aedge(i*m+j,T,-t);
				else{aedge(S,i*m+j,t);sum+=t;}
			}
			//brack
			else{
				aedge(S,n*m+i*m+j,dec(b[i][j]));
				aedge(n*m+i*m+j,i*m+j,inf);
				int t=(dec(b[i][j])-dec(c[i][j]));
				if(t<0) aedge(S,i*m+j,-t);
				else{aedge(i*m+j,T,t);sum+=t;}
				rep(k,4){
					int x=dx[k]+i,y=dy[k]+j;
					if(x<0 || x>=n || y<0 || y>=m) continue;
					aedge(i*m+j,x*m+y+n*m,inf);aedge(i*m+j+m*n,x*m+y,inf);
				}
			}
		}
		return sum-mflow();
	}
};
