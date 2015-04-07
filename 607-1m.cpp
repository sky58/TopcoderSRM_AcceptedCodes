//SRM607DIV1-475 CombinationLockDiv1
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
class CombinationLockDiv1{
	public:
	int minimumMoves(vector<string> c,vector<string> d){
		string a="",b="";
		rep(i,c.size()) a+=c[i];rep(i,d.size()) b+=d[i];
		int n=a.size(),sum=0,out=0;
		vector<int> x,y;
		x.pb(0);
		rep(i,n) x.pb((10+((a[i]-'0')-(b[i]-'0')))%10);
		x.pb(0);
		rep(i,n+1) y.pb((10+x[i+1]-x[i])%10);
		sort(All(y));
		rep(i,n+1) sum+=y[i];
		rep(i,n+1-sum/10) out+=y[i];
		return out;
	}
};
