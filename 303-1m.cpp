//SRM303DIV1-500 Knights
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
vector <vector <int> > gr;vector <int> cl,x,y,gu,ki;
int sumi[1000];

//maxvÇÃílÇ…íçà”
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
void rec(int a,int b,int c){
	if(sumi[a]>0) return;
	sumi[a]=b*2+c%2;
	int i;
	for(i=0;i<gr[a].size();i++) rec(gr[a][i],b,c+1);
	return;
}
class Knights{
	public:
	int Knights::makeFriendly(int a,vector <string> b){
		int i,j,n;string s;
		memset(sumi,0,sizeof(sumi));
		for(j=0;j<b.size();j++){
			istringstream sin(b[j]);
			while(sin>>s){
				x.pb(s[0]-'A');int t=0;
				for(i=1;i<s.size();i++) t=t*10+(s[i]-'0');y.pb(t);
			}
		}
		n=x.size();for(i=0;i<n;i++) gr.pb(cl);
		for(i=0;i<n;i++) for(j=0;j<n;j++) if(abs(x[i]-x[j])*abs(y[i]-y[j])==2) gr[i].pb(j);
		for(i=0;i<n;i++) rec(i,i+1,0);
		for(i=0;i<n;i++){if(sumi[i]%2==0) gu.pb(i);else ki.pb(i);}
//		for(i=0;i<gu.size();i++) cout<<gu[i]<<endl;for(i=0;i<ki.size();i++) cout<<ki[i]<<endl;
//		for(i=0;i<n;i++) cout<<sumi[i]<<endl;
		V=n+2;S=n;T=n+1;
		for(i=0;i<gu.size();i++){
			aedge(n,gu[i],1);for(j=0;j<gr[gu[i]].size();j++) aedge(gu[i],gr[gu[i]][j],1);
		}
		for(i=0;i<ki.size();i++) aedge(ki[i],n+1,1);
		return mflow();
	}
};
