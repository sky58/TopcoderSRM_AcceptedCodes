//SRM527DIV1-1050 P8XCoinChange
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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[2][1000010];
int mo=1000003;
int cal(int a){
	if(a>=mo) return a-mo;return a;
}
class P8XCoinChange{
	public:
	int P8XCoinChange::solve(long long b,vector <long long> a){
		int i,j,n=a.size();
//		lint x=1000000000000000000LL,y=999999999999LL;cout<<x%y<<endl;
		rep(i,mo) dp[0][i]=1;
		REP(i,1,n){
			int now=i%2,next=(i+1)%2;lint T=(b%a[i])/a[i-1],D=a[i]/a[i-1];
			T%=mo;D%=mo;int t=(int)T,d=(int)D;
			rep(j,mo){
//				lint t=(b%a[i]+a[i]*j)/a[i-1];
				dp[now][j]=dp[next][t];
				if(j>0) dp[now][j]=cal(dp[now][j]+dp[now][j-1]);
//				if(i==2) cout<<dp[now][j]<<' '<<t<<endl;
				t+=d;if(t>=mo) t-=mo;
			}
//			cout<<dp[now][mo-1]<<endl;if(i==1) cout<<dp[now][5]<<endl;
		}
		return dp[(n-1)%2][(b/a[n-1])%mo];
	}
};
