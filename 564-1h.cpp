//SRM564DIV1-850 DefectiveAddition
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
//lint dp[55][2];
lint mo=1000000007;
class DefectiveAddition{
	public:
	int DefectiveAddition::count(vector <int> a,int b){
		int t=1,i,j,n=a.size();lint out=0;
		sort(All(a));
		while(t*2<=a[n-1]+1) t*=2;
		if(b>=t*2) return 0;
		lint dp[55][2];
		memset(dp,0,sizeof(dp));dp[0][0]=1;
		rep(i,n-1) rep(j,2){
			dp[i+1][j]+=dp[i][j]*min(t,a[i]+1);dp[i+1][j]%=mo;
			dp[i+1][j^1]+=dp[i][j]*max(0,a[i]-t+1);dp[i+1][j^1]%=mo;
		}
		if(b<0 || b>=t) out=dp[n-1][1];else out=dp[n-1][0];
		if(a[n-1]>=t){
			vector <int> a2;
			rep(i,n) a2.pb(a[i]);
			a2[n-1]-=t;
			out=(out+count(a2,(b^t)))%mo;
		}
		return (int)out;
	}
};
