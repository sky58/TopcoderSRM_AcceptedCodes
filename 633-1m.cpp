//SRM633DIV1-600 DoubleTree
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
namespace MF{
	#define MAXN 25252
	#define MAXM 364364
	#define wint int
	const wint wEPS=0;
	const wint wINF=1001001001;
	int n,m,ptr[MAXN],next[MAXM],zu[MAXM];
	wint capa[MAXM],tof;
	int lev[MAXN],see[MAXN],que[MAXN],*qb,*qe;
	void init(int _n){
		n=_n;m=0;memset(ptr,~0,n*4);
	}
	void ae(int u,int v,int w0,int w1=0){
		next[m]=ptr[u];ptr[u]=m;zu[m]=v;capa[m]=w0;++m;
		next[m]=ptr[v];ptr[v]=m;zu[m]=u;capa[m]=w1;++m;
	}
	wint augment(int src,int ink,wint flo){
		if(src==ink) return flo;
		wint f;
		for(int &i=see[src];~i;i=next[i]) if(capa[i]>wEPS && lev[src]<lev[zu[i]]){
			if((f=augment(zu[i],ink,min(flo,capa[i])))>wEPS){
				capa[i]-=f;capa[i^1]+=f;return f;
			}
		}
		return 0;
	}
	bool solve(int src,int ink,wint flo=wINF){
		wint f;
		int i,u,v;
		for(tof=0;tof+wEPS<flo;){
			qb=qe=que;
			memset(lev,~0,n*4);
			for(lev[*qe++=src]=0,see[src]=ptr[src];qb!=qe;){
				for(i=ptr[u=*qb++];~i;i=next[i]) if(capa[i]>wEPS && !~lev[v=zu[i]]){
					lev[*qe++=v]=lev[u]+1;see[v]=ptr[v];
					if(v==ink) goto au;
				}
			}
			return 0;
		au:	for(;(f=augment(src,ink,flo-tof))>wEPS;tof+=f);
		}
		return 1;
	}
}
vector<int> gr[2][58];
//int pa[2][58];
bool g2[58][58];
void dfs(int id,int v,int u){
	if(u>=0) g2[u][v]=true;
	rep(i,gr[id][v].size()){
		int w=gr[id][v][i];
		if(w==u) continue;
		dfs(id,w,v);
	}
}
class DoubleTree{
	public:
	int maximalScore(vector<int> a,vector<int> b,vector <int> c,vector<int> d,vector<int> e){
		int n=e.size(),s=n*2,t=s+1,v=t+1,inf=1000001001,out=0;
		rep(i,n-1){
			gr[0][a[i]].pb(b[i]);gr[0][b[i]].pb(a[i]);
			gr[1][c[i]].pb(d[i]);gr[1][d[i]].pb(c[i]);
		}
		rep(i,n) rep(j,n){
			memset(g2,false,sizeof(g2));
			dfs(0,i,-1);dfs(1,j,-1);
			rep(m,n) rep(k,n) rep(l,n){if(g2[k][m] && g2[m][l]) g2[k][l]=true;}
			MF::init(v);
			int ret=0;
			rep(k,n){
				if(e[k]>0) ret+=e[k],MF::ae(s,k,e[k]);
				else MF::ae(k+n,t,-e[k]);
				/*MF::ae(k,k+n,inf);
				if(pa[0][k]>=0) MF::ae(k,pa[0][k]+n,inf);
				if(pa[1][k]>=0) MF::ae(k,pa[1][k]+n,inf);*/
				rep(l,n){
					if(g2[l][k]) MF::ae(k,l+n,inf);
				}
			}
			MF::solve(s,t);
			//cout<<i<<' '<<j<<' '<<ret<<' '<<MF::tof<<endl;
			out=max(out,ret-MF::tof);
		}
		return out;
	}
};
