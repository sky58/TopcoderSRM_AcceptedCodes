//SRM559DIV1-900 CircusTents
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
typedef pair<double,double> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <double> dx,dy,d,d2,th,t2,r;int n;
double r0,pi=3.14159265358979;
double sq(double a){return a*a;}
bool ch(double a){
	int i;vector <pint> b,c;//cout<<a<<endl;
	rep(i,n){
		if(d[i]>a+r0+r[i]) continue;
		if(d2[i]<a+r[i]){
			double rest=(a+r[i]-d2[i])/r0;
			if(rest+t2[i]>=pi) b.pb(mp(0,2*pi));
			else b.pb(mp(th[i]-t2[i]-rest,th[i]+t2[i]+rest));
		}
		else{
			//cout<<i<<endl;
			//cout<<(-sq(r[i]+a)+sq(r0)+sq(d[i]))/(2.0*r0*d[i])<<endl;
			double rest=acos((-sq(r[i]+a)+sq(r0)+sq(d[i]))/(2.0*r0*d[i]));
			//cout<<rest<<endl;
			b.pb(mp(th[i]-rest,th[i]+rest));
		}
	}
	rep(i,b.size()){
		double l=b[i].fi,h=b[i].se;//cout<<l<<' '<<h<<endl;
		if(l<0){l+=2*pi;h+=2*pi;}
		if(h>2*pi){c.pb(mp(l,2*pi));c.pb(mp(0,h-2*pi));}
		else c.pb(mp(l,h));
	}
	sort(All(c));double now=0.0;
	rep(i,c.size()){
		//cout<<c[i].fi<<' '<<c[i].se<<endl;
		if(c[i].fi>now+1e-13) return false;now>?=c[i].se;
	}
	if(2*pi-now<1e-13) return true;return false;
}
class CircusTents{
	public:
	double CircusTents::findMaximumDistance(vector <int> X,vector <int> Y,vector <int> R){
		n=X.size()-1;int i;r0=R[0];
		rep(i,n){dx.pb(X[i+1]-X[0]);dy.pb(Y[i+1]-Y[0]);d.pb(sqrt(dx[i]*dx[i]+dy[i]*dy[i]));r.pb(R[i+1]);}
		rep(i,n){th.pb(atan2(dy[i],dx[i]));t2.pb(acos(r0/d[i]));d2.pb(d[i]*sin(t2[i]));}
		double lo=0,hi=1e10;
		rep(i,100){
			//cout<<lo<<' '<<hi<<endl;
			double mi=(lo+hi)/2;if(!ch(mi)) lo=mi;else hi=mi;
		}
		return hi;
	}
};
