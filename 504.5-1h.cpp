//SRM504.5DIV1-900
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
double dp[1100][1100];
class TheTicketsDivOne{
	public:
	double TheTicketsDivOne::find(int n,int m){
		dp[1][1]=1.0;int i,j;
		for(i=2;i<1050;i++){
			double t=1.0/6.0;
			for(j=1;j<i;j++) t=t/2.0+dp[i-1][j]/3.0;
			dp[i][i]=t/(1.0-pow(0.5,i));dp[i][1]=dp[i][i]/2.0+1.0/6.0;
			for(j=2;j<i;j++) dp[i][j]=dp[i][j-1]/2.0+dp[i-1][j-1]/3.0;
		}
		return dp[n][m];
	}
};
