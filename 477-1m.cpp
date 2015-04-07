//SRM477DIV1-500 PythTriplets
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
#define pb push_back
typedef long long lint;
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
lint gcd( lint m, lint n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
bool ch(lint a){
	lint b=(lint)sqrt(1.0*a+1e-5);
	if(b*b==a) return true;return false;
}
class PythTriplets{
	public:
	int PythTriplets::findMax(vector <string> s){
		string st;int i,j,t,n,m;vector <lint> odd,even;
		for(i=0;i<s.size();i++) st+=s[i];istringstream sin(st);
		while(sin>>t){if(t%2==0) even.pb(t);else odd.pb(t);}
		n=even.size();m=odd.size();V=n+m+2;S=n+m;T=n+m+1;
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(gcd(even[i],odd[j])>1) continue;
			if(ch(even[i]*even[i]+odd[j]*odd[j])) aedge(i,n+j,1);
		}
		for(i=0;i<n;i++) aedge(n+m,i,1);for(j=0;j<m;j++) aedge(n+j,n+m+1,1);
		return mflow();
	}
};
