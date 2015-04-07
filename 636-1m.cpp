//SRM636DIV1-500 ClosestRabbit
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
double co[514][514];
class ClosestRabbit{
	public:
	double getExpected(vector<string> a,int b){
		int h=a.size(),w=a[0].size(),e=0;
		double out=0.0;
		rep(i,514) rep(j,514) co[i][j]=0.0;
		rep(i,514){
			co[i][0]=co[i][i]=1.0;
			REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1]);
		}
		rep(i,h) rep(j,w) e+=(a[i][j]=='.');//cout<<e<<endl;
		rep(i,h) rep(j,w) rep(k,h) rep(l,w){
			if(a[i][j]=='#' || a[k][l]=='#' || (i*w+j)>=(k*w+l)) continue;
			int x=0,d=(i-k)*(i-k)+(j-l)*(j-l);
			//cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
			rep(m,h) rep(n,w){
				if(a[m][n]=='#') continue;
				int d1=(i-m)*(i-m)+(j-n)*(j-n),d2=(k-m)*(k-m)+(l-n)*(l-n);
				if(d1<d || d2<d) continue;
				if(d1==d && (m*w+n)<=(k*w+l)) continue;
				if(d2==d && (m*w+n)<=(i*w+j)) continue;
				x++;
			}
			//cout<<e<<' '<<x<<endl;cout<<co[e-x][b-2]/co[e][b]<<endl;
			out+=co[x][b-2]/co[e][b];
		}
		return out;
	}
};
