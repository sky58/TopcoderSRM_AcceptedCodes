//SRM272DIV1-500 RoundTable
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
lint dp[55][3][7][7][55];
class RoundTable{
	public:
	long long RoundTable::arrangements(int a,int b,int n,int d){
		int i,j,k,l;lint out=0;
		for(i=0;i<55;i++) for(j=0;j<7;j++) for(k=0;k<7;k++) for(l=0;l<55;l++) dp[i][0][j][k][l]=dp[i][1][j][k][l]=0;
		dp[1][0][1][0][1]=1;
		for(i=1;i<n;i++) for(j=0;j<=a;j++) for(k=0;k<=b;k++) for(l=0;l<52;l++){
//			if(l<7) cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<dp[i][0][j][k][l]<<' '<<dp[i][1][j][k][l]<<endl;
			dp[i+1][0][j][k][l+1]+=dp[i][0][j][k][l];
			dp[i+1][1][j][k][l+1]+=dp[i][1][j][k][l];
			if(j<a){
				dp[i+1][0][j+1][k][1]+=dp[i][0][j][k][l]*(a-j);
				if(l>=d) dp[i+1][0][j+1][k][1]+=dp[i][1][j][k][l]*(a-j);
			}
			if(k<b && n-i>=d){
				dp[i+1][1][j][k+1][1]+=dp[i][1][j][k][l]*(b-k);
				if(l>=d) dp[i+1][1][j][k+1][1]+=dp[i][0][j][k][l]*(b-k);
			}
		}
		for(l=0;l<53;l++) out+=(dp[n][0][a][b][l]+dp[n][1][a][b][l]);return out*n;
	}
};
