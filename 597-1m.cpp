//SRM597DIV1-600 ConvexPolygonGame
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
double eps=1e-8;
int gau(double a){
	return (int)(a+200000)-200000;
}
class ConvexPolygonGame{
	public:
	string winner(vector <int> x,vector <int> y){
		vector <pint> p;int n=x.size();x.pb(x[0]);y.pb(y[0]);
		REP(i,-100010,100010){
			double lo=110000,hi=-lo;
			rep(j,n){
				int ax=x[j],ay=y[j],bx=x[j+1],by=y[j+1];
				if(ax==bx) continue;
				if(ax>bx){
					int d=ax;ax=bx;bx=d;d=ay;ay=by;by=d;
				}
				if(ax==i){
					lo=min(lo,ay+2*eps);hi=max(hi,ay-2*eps);
				}
				else if(bx==i){
					lo=min(lo,by+2*eps);hi=max(hi,by-2*eps);
				}
				else if(ax<bx && ax<=i && i<=bx){
					double t=ay+1.0*(by-ay)/(bx-ax)*(i-ax);
					lo=min(lo,t);hi=max(hi,t);
				}
			}
			int le=gau(lo-eps)+1,ri=gau(hi+eps);
			if(le<=ri) p.pb(mp(i,le));if(le<ri) p.pb(mp(i,ri));
		}
		//rep(i,p.size()) cout<<p[i].fi<<' '<<p[i].se<<endl;
		if(p.size()<3) return "Petya";
		lint dx=p[1].fi-p[0].fi,dy=p[1].se-p[0].se;
		rep(i,p.size()){
			if(dx*(p[i].se-p[0].se)!=dy*(p[i].fi-p[0].fi)) return "Masha";
		}
		return "Petya";
	}
};
