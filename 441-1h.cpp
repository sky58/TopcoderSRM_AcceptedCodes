//SRM441DIV1-1000 PaperAndPaint
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
typedef pair<pint,pint> qint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<qint> qu;
vector<int> x,y;
short num[210][114514];
class PaperAndPaint{
	public:
	long long computeArea(int w,int h,vector<int> xf,vector<int> cnt,vector<int> xl,vector<int> yl, vector<int> xh,vector<int> yh){
		int q=xl.size();lint out=0;
		rep(i,q){
			int xl1=max(0,xf[i]-xh[i]),xh1=max(0,xf[i]-xl[i]),xl2=min(w,xf[i]+xl[i]),xh2=min(w,xf[i]+xh[i]),d=h/(cnt[i]+1);
			rep(j,cnt[i]+1){
				int yl1,yh1;
				if(j%2==0) yl1=j*d+yl[i],yh1=j*d+yh[i];
				else yl1=(j+1)*d-yh[i],yh1=(j+1)*d-yl[i];
				qu.pb(mp(mp(xl1,xh1),mp(yl1,yh1)));
				qu.pb(mp(mp(xl2,xh2),mp(yl1,yh1)));
			}
		}
		x.pb(0);x.pb(w);y.pb(0);y.pb(h);
		rep(i,qu.size()){
			x.pb(qu[i].fi.fi);x.pb(qu[i].fi.se);y.pb(qu[i].se.fi);y.pb(qu[i].se.se);
		}
		sort(All(x));x.erase(unique(All(x)),x.end());sort(All(y));y.erase(unique(All(y)),y.end());
		memset(num,0,sizeof(num));int n=x.size(),m=y.size();
		//rep(i,n) cout<<x[i]<<' ';cout<<endl;rep(i,m) cout<<y[i]<<' ';cout<<endl;
		rep(i,qu.size()){
			int xl1=lower_bound(All(x),qu[i].fi.fi)-x.begin();
			int xh1=lower_bound(All(x),qu[i].fi.se)-x.begin();
			int yl1=lower_bound(All(y),qu[i].se.fi)-y.begin();
			int yh1=lower_bound(All(y),qu[i].se.se)-y.begin();
			REP(j,xl1,xh1) num[j][yl1]++,num[j][yh1]--;
		}
		rep(i,n-1){
			int now=0;
			rep(j,m-1){
				now+=num[i][j];
				//cout<<i<<' '<<j<<' '<<now<<endl;
				if(now<1) out+=(lint)(x[i+1]-x[i])*(y[j+1]-y[j]);
			}
		}
		return out;
	}
};
