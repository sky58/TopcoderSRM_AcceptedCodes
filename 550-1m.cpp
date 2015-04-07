//SRM550DIV1-500 CheckerExpansion
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
bool ok(lint x,lint y){
	if(y>x) return false;
	if(x==0) return true;
	lint t=1;
	while(t*2<=x) t*=2;
	return ok(x%t,y%t);
}
char cal(lint t,lint x,lint y){
	if((x+y)%2>0) return '.';
	x=(x+y)/2;
	if(x>t) return '.';
	if(ok(x,y)){
		if(x%2==0LL) return 'A';return 'B';
	}
	return '.';
}
class CheckerExpansion{
	public:
	vector<string> resultAfter(long long t,long long x0,long long y0,int w,int h){
		vector<string> out;
		rep(i,h){
			string s="";
			rep(j,w) s+=cal(t-1,x0+j,y0+h-1-i);
			out.pb(s);
		}
		return out;
	}
};
