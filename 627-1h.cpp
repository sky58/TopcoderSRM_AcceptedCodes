//SRM627DIV1-1000 LaserTowersDiv1
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
	#define MAXN 25100
	#define MAXM 50100
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
class LaserTowersDiv1{
	public:
	int countMaxEnemies(vector<string> a){
		int n=a.size(),m=a[0].size(),s=2*n*m,t=s+1,v=t+1,inf=1001001001,out=0;
		string st="AV<>";
		int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
		MF::init(v);
		rep(i,n) rep(j,m){
			MF::ae(i*m+j,n*m+i*m+j,inf);
			int d=-1,ma=-1,m2=0;
			rep(k,4){if(st[k]==a[i][j]) d=k;}
			if(d<0) continue;
			if(d<2) MF::ae(s,i*m+j,inf);else MF::ae(n*m+i*m+j,t,inf);
			REP(k,1,55){
				int x=i+dx[d]*k,y=j+dy[d]*k;
				if(x<0 || y<0 || x>=n || y>=m) break;
				if(a[x][y]>='0' && a[x][y]<='9') ma=max(ma,(a[x][y]-'0'));
			}
			//cout<<i<<' '<<j<<' '<<d<<' '<<ma<<endl;
			if(ma<0) continue;out+=ma;
			REP(k,1,55){
				int x=i+dx[d]*k,y=j+dy[d]*k,px=x-dx[d],py=y-dy[d];
				if(x<0 || y<0 || x>=n || y>=m) break;
				if(d<2) MF::ae(px*m+py,x*m+y,ma-m2);
				else MF::ae(n*m+x*m+y,n*m+px*m+py,ma-m2);
				if(a[x][y]>='0' && a[x][y]<='9') m2=max(m2,(a[x][y]-'0'));
			}
		}
		//cout<<out<<endl;
		MF::solve(s,t);
		return out-MF::tof;
	}
};
