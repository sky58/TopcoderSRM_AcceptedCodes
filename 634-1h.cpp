//SRM634DIV1-1000 SegmentCutting
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
typedef pair<double,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1);
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
struct Pt {
	double x, y;
	Pt() {}
	Pt(double x, double y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const double &k) const { return Pt(x * k, y * k); }
	Pt operator/(const double &k) const { return Pt(x / k, y / k); }
	double abs() const { return sqrt(x * x + y * y); }
	double abs2() const { return x * x + y * y; }
	double arg() const { return atan2(y, x); }
	double dot(const Pt &a) const { return x * a.x + y * a.y; }
	double det(const Pt &a) const { return x * a.y - y * a.x; }
};
ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
double tri(const Pt &a, const Pt &b, const Pt &c) { return (b - a).det(c - a); }
lint ax1,ay1,bx1,by1,ax2,ay2,bx2,by2,anum,bnum;
lint cal(vector<lint> x,vector<lint> y){
	ax1=ay1=bx1=by1=ax2=ay2=bx2=by2=anum=bnum=0;
	vector<pint> a,b;int n=x.size(),ia=0,ib=0;
	//cout<<n<<endl;
	rep(i,n){
		double arg=Pt(x[i],y[i]).arg();
		if(arg>0.0) a.pb(mp(arg,i)),ax1+=x[i],ay1+=y[i],ax2+=x[i]*x[i],ay2+=y[i]*y[i],anum++;
		else b.pb(mp(arg+PI,i)),bx1+=x[i],by1+=y[i],bx2+=x[i]*x[i],by2+=y[i]*y[i],bnum++;
	}
	//cout<<anum<<bnum<<endl;
	lint ret=bnum*(ax2+ay2)+anum*(bx2+by2)-2*(ax1*bx1+ay1*by1)+max(ax2+ay2,bx2+by2);
	sort(All(a));sort(All(b));a.pb(mp(2*PI,-1));b.pb(mp(2*PI,-1));
	rep(i,n){
		if(a[ia].fi<b[ib].fi){
			int j=a[ia].se;
			ax1-=x[j];ay1-=y[j];ax2-=x[j]*x[j];ay2-=y[j]*y[j];anum--;
			bx1+=x[j];by1+=y[j];bx2+=x[j]*x[j];by2+=y[j]*y[j];bnum++;
			ret=max(ret,bnum*(ax2+ay2)+anum*(bx2+by2)-2*(ax1*bx1+ay1*by1)+max(ax2+ay2,bx2+by2));
			ia++;
		}
		else{
			int j=b[ib].se;
			ax1+=x[j];ay1+=y[j];ax2+=x[j]*x[j];ay2+=y[j]*y[j];anum++;
			bx1-=x[j];by1-=y[j];bx2-=x[j]*x[j];by2-=y[j]*y[j];bnum--;
			ret=max(ret,bnum*(ax2+ay2)+anum*(bx2+by2)-2*(ax1*bx1+ay1*by1)+max(ax2+ay2,bx2+by2));
			ib++;
		}
	}
	return ret;
}
class SegmentCutting{
	public:
	long long maxValue(vector<int> x,vector<int> y){
		lint out=0;int n=x.size();//cout<<n<<endl;
		rep(i,n){
			vector<lint> x2,y2;
			rep(j,n){
				if(i==j) continue;
				x2.pb(x[j]-x[i]);y2.pb(y[j]-y[i]);
			}
			//cout<<x2.size()<<endl;
			out=max(out,cal(x2,y2));
		}
		return out;
	}
};
