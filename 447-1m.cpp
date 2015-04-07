//SRM447DIV1-500 PropleYouMayKnow
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
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
class PeopleYouMayKnow{
	public:
	int PeopleYouMayKnow::maximalScore(vector <string> a,int a1,int a2){
		int out=0,i,j,n=a.size();V=n*2;S=a1;T=a2;
		vector <int> s1,s2;
		for(i=0;i<n;i++){
			if(a[a1][i]=='Y' && a[a2][i]=='Y') out++;
		}
		for(i=0;i<n;i++){
			if(a[a1][i]=='Y' && a[a2][i]=='N') s1.pb(i);
			if(a[a2][i]=='Y' && a[a1][i]=='N') s2.pb(i);
		}
		for(i=0;i<s1.size();i++) for(j=0;j<s2.size();j++){
			if(a[s1[i]][s2[j]]=='Y'){
				add_edge(s1[i],s2[j],1);
//				cout<<s1[i]<<' '<<s2[j]<<' '<<'\n';
			}
		}
		for(i=0;i<s1.size();i++) add_edge(a1,s1[i],1);
		for(i=0;i<s2.size();i++) add_edge(s2[i],a2,1);
		return out+max_flow();
	}
};
