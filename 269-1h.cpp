//SRM269DIV1-1000 PieSharing
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[55][55][55];
class PieSharing{
	public:
	int PieSharing::share(vector <int> a){
		int i,j,k,n=a.size(),out=0;
		memset(dp,0,sizeof(dp));dp[1][1][1]=a[0];
		for(i=1;i<n;i++) for(j=0;j<=i;j++) for(k=0;k<=n/3;k++){
//			cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			dp[i+1][j][k]>?=dp[i][j][k];
			if(j<i) if(i<n-1) dp[i+1][i+1][k+1]>?=dp[i][j][k]+a[i];
		}
		for(i=0;i<=n;i++) out>?=dp[n][i][n/3];
		memset(dp,0,sizeof(dp));//dp[1][0][1]=a[i];
		for(i=1;i<n;i++) for(j=0;j<=i;j++) for(k=0;k<=n/3;k++){
			dp[i+1][j][k]>?=dp[i][j][k];
			if(j<i) dp[i+1][i+1][k+1]>?=dp[i][j][k]+a[i];
		}
		for(i=0;i<=n;i++) out>?=dp[n][i][n/3];
		return out;
	}
};
