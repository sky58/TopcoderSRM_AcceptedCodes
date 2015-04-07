//有向最小全域木（隣接行列Ver,経路復元も行う）
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
typedef int typ;
typ inf=100000000;
int ng=0;
vector<int> dmst(int root,int V,vector<vector<typ> > gr){
	vector<int> ret(V,-1),id(V,-1),vis(V,-1);
	rep(i,V) rep(j,V){
		if(i==root || i==j) continue;
		if(ret[i]<0){
			if(gr[j][i]<inf) ret[i]=j;
		}
		else if(gr[ret[i]][i]>gr[j][i]) ret[i]=j;
	}
	rep(i,V){if(i!=root && ret[i]<0) ng=1;}
	int t=0;
	rep(i,V){
		int v=i;
		while(vis[v]!=i && id[v]==-1 && v!=root){
			vis[v]=i;v=ret[v];
		}
		if(v!=root && id[v]==-1){
			for(int u=ret[v];u!=v;u=ret[u]) id[u]=t;id[v]=t++;
		}
	}
	if(t==0) return ret;
	rep(i,V){if(id[i]==-1) id[i]=t++;}
	vector<typ> tmp(t,inf);vector<vector<typ> > gr2(t,tmp);
	vector<int> tm2(t,-1);vector<vector<int> > from(t,tm2),to(t,tm2);
	rep(i,V) rep(j,V){
		if(id[i]==id[j] || gr[i][j]>=inf || j==root) continue;
		int co=gr[i][j]-gr[ret[j]][j],u=id[i],v=id[j];
		if(from[u][v]<0 || gr2[u][v]>co){
			from[u][v]=i;to[u][v]=j;gr2[u][v]=co;
		}
	}
	vector<int> nex=dmst(id[root],t,gr2);
	rep(i,t){
		if(nex[i]>=0) ret[to[nex[i]][i]]=from[nex[i]][i];
	}
	return ret;
}
class FoxTheLinguist{
	public:
	int minimalHours(int n,vector<string> a){
		string b="",s;rep(i,a.size()) b+=a[i];int V=n*10+1;
		vector<typ> tmp(V,inf);vector<vector<typ> > gr(V,tmp);
		istringstream sin(b);
		while(sin>>s){
			int pt=(s[0]-'A'),pl=(s[1]-'0'),nt=(s[4]-'A'),nl=(s[5]-'0');
			int ti=(s[7]-'0')*1000+(s[8]-'0')*100+(s[9]-'0')*10+(s[10]-'0');
			//ed.pb((edge){pt*10+pl,nt*10+nl,ti});
			gr[pt*10+pl][nt*10+nl]=min(gr[pt*10+pl][nt*10+nl],ti);
		}
		rep(i,n){
			//ed.pb((edge){V-1,i*10,0});
			gr[V-1][i*10]=0;
			rep(j,9){
				//ed.pb((edge){i*10+j+1,i*10+j,0});
				gr[i*10+j+1][i*10+j]=0;
			}
		}
		vector<int> ret=dmst(V-1,V,gr);if(ng>0) return -1;
		int out=0;rep(i,V-1) out+=gr[ret[i]][i];return out;
	}
};
