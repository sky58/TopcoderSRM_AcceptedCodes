//SRM599DIV1-500 FindPolygons
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
vector<int> x,y,z;
class FindPolygons{
	public:
	double minimumPolygon(int l){
		if(l<4 || l%2>0) return -1.0;
		double out=1e9;
		/*REP(i,1,l+1) REP(j,1,l-i+1){
			if(i*i+j*j==(l-i-j)*(l-i-j)){
				//cout<<i<<' '<<j<<' '<<l-i-j<<endl;
				out=min(out,1.0*(l-i-j)-min(i,j));
			}
		}*/
		REP(i,0,5100) REP(j,i,5100){
			int k=(int)(1e-8+sqrt(i*i+j*j));
			if(k<2510 && i*i+j*j==k*k){
				x.pb(i);y.pb(j);z.pb(k);
				x.pb(j);y.pb(i);z.pb(k);
			}
		}
		int n=x.size();
		//rep(i,n){if(x[i]*x[i]+y[i]*y[i]!=z[i]*z[i]) cout<<i<<endl;}
		rep(i,n) REP(j,i+1,n){
			if(x[i]*y[j]==x[j]*y[i]) continue;
			int t=l-z[i]-z[j];if(t<1) continue;
			if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==t*t){
				int ma=max(z[i],max(z[j],t)),mi=min(z[i],min(z[j],t));
				out=min(out,1.0*ma-mi);
				if(ma-mi==819) cout<<x[i]<<' '<<x[j]<<' '<<y[i]<<' '<<y[j]<<endl;
			}
		}
		if(out<1e8) return out;
		if(l%4==0) return 0.0;return 1.0;
	}
};
