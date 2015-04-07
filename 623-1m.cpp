//SRM623DIV1-450 CatchTheBeat
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
typedef pair<lint,lint> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<lint> x,y;
vector<pint> p;
lint inf=7658769611054LL;
lint dp[765876];
class CatchTheBeat{
	public:
	int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset){
		x.pb(x0);rep(i,n-1) x.pb((x[i]*a+b)%mod1);rep(i,n) x[i]-=offset;
		y.pb(y0);rep(i,n-1) y.pb((y[i]*c+d)%mod2);
		rep(i,n){
			if(x[i]+y[i]>=0LL && y[i]>=x[i]) p.pb(mp(x[i]+y[i],-x[i]+y[i]));
		}
		int m=p.size(),out=0;
		if(m<1) return 0;
		sort(All(p));
		rep(i,765876) dp[i]=inf;dp[0]=0;
		//cout<<m<<endl;
		rep(i,m){
			//if(i<m-1 && p[i]==p[i+1]) cout<<i<<endl;
			lint t=p[i].se;
			int s=lower_bound(dp,dp+m+5,t+1)-dp;
			out=max(out,s);
			dp[s]=t;
		}
		return out;
	}
};
