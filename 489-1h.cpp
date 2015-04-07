//SRM489DIV1-1000 AppleTrees
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
lint co[101000][42];
lint dp[42][42][1610];
lint mo=1000000007;
class AppleTrees{
	public:
	int AppleTrees::theCount(int a,vector <int> b){
		int n=b.size(),i,j,k;lint out=0;sort(b.begin(),b.end());
		for(i=0;i<101000;i++) for(j=0;j<42;j++) co[i][j]=0;co[0][0]=1;
		for(i=1;i<100500;i++) for(j=0;j<=i && j<42;j++){
			co[i][j]+=co[i-1][j];if(j>0) co[i][j]+=co[i-1][j-1];co[i][j]%=mo;
		}
		for(i=0;i<42;i++) for(j=0;j<42;j++) for(k=0;k<1610;k++) dp[i][j][k]=0;dp[0][0][0]=1;
		for(i=0;i<n;i++) for(j=0;j<=n;j++) for(k=0;k<1605;k++){
			if(dp[i][j][k]<=0) continue;
			dp[i+1][j+1][k]=(dp[i+1][j+1][k]+dp[i][j][k]*(j+1))%mo;
			if(j>1 && k+2*b[i]<=1600) dp[i+1][j-1][k+2*b[i]]=(dp[i+1][j-1][k+2*b[i]]+dp[i][j][k]*(j-1))%mo;
			if(j>0 && k+b[i]<=1600) dp[i+1][j][k+b[i]]=(dp[i+1][j][k+b[i]]+dp[i][j][k]*2*j)%mo;
		}
		for(i=0;i<=1600 && i<a;i++) out=(out+dp[n][1][i]*co[a-i-1+n][n])%mo;return out;
	}
};
