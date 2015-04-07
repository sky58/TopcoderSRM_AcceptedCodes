//SRM556DIV1-500 LeftRightDigitsGame2
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
string a,b,inf="99999999999999999999999999999999999999999999999999999999";
int n;
string dp[55][55][3][3];
string cal(int x,int y,int l,int r){
	//cout<<x<<' '<<y<<' '<<l<<' '<<r<<endl;
	if(dp[x][y][l][r].size()>0) return dp[x][y][l][r];
	string ret=inf;int nl,nr;
	if(x+1==y){
		if(l==2 || (l==1 && a[0]>b[x]) || (l==1 && a[0]==b[x] && r>=1)) return a.substr(0,1);return inf;
	}
	if(l==0) return inf;
	if(l==2) nl=2;if(l==1){if(a[y-x-1]>b[x]) nl=2;if(a[y-x-1]==b[x]) nl=1;if(a[y-x-1]<b[x]) nl=0;}
	if(a[y-x-1]>b[y-1]) nr=2;if(a[y-x-1]<b[y-1]) nr=0;if(a[y-x-1]==b[y-1]) nr=r;
	if(cal(x+1,y,nl,r)<inf) ret=min(ret,a[y-x-1]+cal(x+1,y,nl,r));
	if(cal(x,y-1,l,nr)<inf) ret=min(ret,cal(x,y-1,l,nr)+a[y-x-1]);
	//cout<<x<<' '<<y<<' '<<l<<' '<<r<<' '<<ret<<endl;
	return dp[x][y][l][r]=ret;
}
class LeftRightDigitsGame2{
	public:
	string LeftRightDigitsGame2::minNumber(string A,string B){
		a=A;b=B;n=a.size();
		string out=cal(0,n,1,1);
		if(out>=inf) return "";return out;
	}
};
