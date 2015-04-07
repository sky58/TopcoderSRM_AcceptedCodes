//SRM562DIV1-500 CheckerFreeness
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
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

double ccw2(P a,P b,P c){
	b-=a;c-=a;return imag(conj(b)*c);
}
	
struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a); push_back(b);
  }
};
bool intersectSS(const L &s, const L &t) {
  return ccw2(s[0],s[1],t[0])*ccw2(s[0],s[1],t[1]) <= 0 &&
         ccw2(t[0],t[1],s[0])*ccw2(t[0],t[1],s[1]) <= 0;
}
vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}
class CheckerFreeness{
	public:
	string isFree(vector <string> WX,vector <string> WY,vector <string> BX,vector <string> BY){
		string wX="",wY="",bX="",bY="";vector <lint> wx,wy,bx,by;int i,j,k;lint t;
		rep(i,WX.size()) wX+=WX[i];istringstream sin1(wX);while(sin1>>t) wx.pb(t);
		rep(i,WY.size()) wY+=WY[i];istringstream sin2(wY);while(sin2>>t) wy.pb(t);
		rep(i,BX.size()) bX+=BX[i];istringstream sin3(bX);while(sin3>>t) bx.pb(t);
		rep(i,BY.size()) bY+=BY[i];istringstream sin4(bY);while(sin4>>t) by.pb(t);
		int n=wx.size(),m=bx.size();if(n<2 || m<2) return "YES";
		vector <P> b,w;
		rep(i,n) w.pb(P(wx[i],wy[i]));rep(i,m) b.pb(P(bx[i],by[i]));
		if(n>2) w=convex_hull(w);if(m>2) b=convex_hull(b);
		//rep(i,w.size()) cout<<(int)real(w[i])<<' '<<(int)imag(w[i])<<endl;cout<<endl;
		//rep(i,b.size()) cout<<(int)real(b[i])<<' '<<(int)imag(b[i])<<endl;cout<<endl;
		w.pb(w[0]);b.pb(b[0]);
		rep(i,w.size()-2) REP(k,i+1,w.size()-1){
			L wl(w[i],w[k]);
			rep(j,b.size()-1){
				L bl(b[j],b[j+1]);
				if(intersectSS(wl,bl)) return "NO";
			}
		}
		rep(j,b.size()-2) REP(k,j+1,b.size()-1){
			L bl(b[j],b[k]);
			rep(i,w.size()-1){
				L wl(w[i],w[i+1]);
				if(intersectSS(wl,bl)) return "NO";
			}
		}
		return "YES";
	}
};
