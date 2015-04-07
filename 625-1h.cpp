//SRM625DIV1-900 Seatfriends
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
lint co[2010][2010],dp[2010][2010];
lint mo=1000000007;
class Seatfriends{
	public:
	int countseatnumb(int n,int m,int g){
		rep(i,2010){
			co[i][0]=co[i][i]=1;
			REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		memset(dp,0,sizeof(dp));dp[1][1]=n;
		REP(i,1,m) REP(j,1,g+1){
			if(i+j+2<=n) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*j)%mo;
			if(j==1 || i+j+1<=n){
				if(i==n-1) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mo;
				else dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j*2)%mo;
			}
			if(j>=2) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j]*j)%mo;
		}
		if(n==m) return (int)(dp[m][1]%mo);
		lint out=0;
		REP(j,1,g+1){
			if(j>n-m) continue;
			out=(out+dp[m][j]*co[n-m-1][j-1])%mo;
		}
		return (int)(out%mo);
	}
};
