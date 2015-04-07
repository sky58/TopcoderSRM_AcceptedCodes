//SRM304DIV1-450 Conditional
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
double dp[55][2600][3];
class Conditional{
	public:
	double Conditional::probability(int n,int m,int v,int s){
		int i,j,k;double out1=0.0,out2=0.0;
		for(i=0;i<55;i++) for(j=0;j<2600;j++) for(k=0;k<3;k++) dp[i][j][k]=0.0;dp[0][0][0]=1.0;
		for(i=0;i<n;i++) for(j=0;j<=m*n;j++) for(k=1;k<=m;k++){
			if(k==v){dp[i+1][j+k][1]+=(dp[i][j][0]+dp[i][j][1])/m;}
			else{dp[i+1][j+k][1]+=dp[i][j][1]/m;dp[i+1][j+k][0]+=dp[i][j][0]/m;}
//			if(k<2) cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
		}
		for(i=0;i<=m*n;i++){out2+=dp[n][i][1];if(i>=s) out1+=dp[n][i][1];}//cout<<out1<<' '<<out2<<endl;
		return out1/out2;
	}
};
