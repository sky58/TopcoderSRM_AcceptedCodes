//SRM595DIV1-900 Constellation
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
typedef pair<pint,double> tint;
vector <tint> po;
int ar[55][55][55];
int di[55][55];
int n;
double prob(int a,int b,int c){
	double ret=po[a].se*po[b].se*po[c].se;
	rep(i,n){
		int f=0;
		if(i<a) f=1;
		if(ar[b][c][i]<0) f=1;
		if(ar[b][c][i]==0){
			if(max(di[b][i],di[c][i])<di[b][c]) f=1;
		}
		if(f>0) ret*=(1.0-po[i].se);
	}
	return ret;
}
class Constellation{
	public:
	double expectation(vector <int> x,vector <int> y,vector <int> p){
		n=x.size();rep(i,n) po.pb(mp(mp(x[i],y[i]),0.001*p[i]));sort(All(po));
		rep(i,n) rep(j,n) rep(k,n){
			int dx1=po[j].fi.fi-po[i].fi.fi,dy1=po[j].fi.se-po[i].fi.se;
			int dx2=po[k].fi.fi-po[i].fi.fi,dy2=po[k].fi.se-po[i].fi.se;
			ar[i][j][k]=dx1*dy2-dx2*dy1;di[i][j]=dx1*dx1+dy1*dy1;
		}
		double out=0.0;
		rep(i,n) REP(j,i+1,n) REP(k,i+1,n){
			if(i!=k && ar[i][j][k]>0) out+=0.5*ar[i][j][k]*prob(i,j,k);
		}
		return out;
	}
};
