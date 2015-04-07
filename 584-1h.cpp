//SRM584DIV1-900 FoxTheLinguist
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
#define MAXV 110
#define MAXE 1100
typedef int typ;
struct edge{ int from,to;typ cost;};
vector<edge> ed;
int pre[MAXV],id[MAXV],vis[MAXV];
typ in[MAXV];
typ inf=100000000;
typ dmst(int root,int V,int E){
	typ ret=0;
	while(1){
		rep(i,V) in[i]=inf;
		rep(i,E){
			int u=ed[i].from,v=ed[i].to;typ w=ed[i].cost;
			if(w<in[v] && u!=v){
				pre[v]=u;in[v]=w;
			}
		}
		rep(i,V){
			if(i==root) continue;
			if(in[i]==inf) return -1;
		}
		int t=0;
		memset(id,-1,sizeof(id));memset(vis,-1,sizeof(vis));
		in[root]=0;
		rep(i,V){
			ret+=in[i];
			int v=i;
			while(vis[v]!=i && id[v]==-1 && v!=root){
				vis[v]=i;v=pre[v];
			}
			if(v!=root && id[v]==-1){
				for(int u=pre[v];u!=v;u=pre[u]) id[u]=t;id[v]=t++;
			}
		}
		if(t==0) break;
		rep(i,V){
			if(id[i]==-1) id[i]=t++;
		}
		rep(i,E){
			int u=ed[i].from,v=ed[i].to;
			ed[i].from=id[u];ed[i].to=id[v];
			if(id[u]!=id[v]) ed[i].cost-=in[v];
		}
		V=t;root=id[root];
	}
	return ret;
}
class FoxTheLinguist{
  public:
  int FoxTheLinguist::minimalHours(int n,vector <string> a){
    string b="",s;rep(i,a.size()) b+=a[i];int V=n*10+1;
    istringstream sin(b);
    while(sin>>s){
      int pt=(s[0]-'A'),pl=(s[1]-'0'),nt=(s[4]-'A'),nl=(s[5]-'0');
      int ti=(s[7]-'0')*1000+(s[8]-'0')*100+(s[9]-'0')*10+(s[10]-'0');
      ed.pb((edge){pt*10+pl,nt*10+nl,ti});
    }
    rep(i,n){
      ed.pb((edge){V-1,i*10,0});
      rep(j,9) ed.pb((edge){i*10+j+1,i*10+j,0});
    }
    return dmst(V-1,V,ed.size());
  }
};
