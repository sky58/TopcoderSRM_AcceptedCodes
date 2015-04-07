//SRM227DIV1-500 TreeSpreading
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
lint dp[12][12][12][12][4];
class TreeSpreading{
	public:
	long long TreeSpreading::countArrangements(int a,int b,int c,int d){
		int i,j,k,l,m;if(a+b+c+d<1) return 1;
		for(i=0;i<12;i++) for(j=0;j<12;j++) for(k=0;k<12;k++) for(l=0;l<12;l++) for(m=0;m<4;m++){
			dp[i][j][k][l][m]=0;
		}
		dp[1][0][0][0][0]=dp[0][1][0][0][1]=dp[0][0][1][0][2]=dp[0][0][0][1][3]=1;
		for(i=0;i<=a;i++) for(j=0;j<=b;j++) for(k=0;k<=c;k++) for(l=0;l<=d;l++){
			dp[i+1][j][k][l][0]+=dp[i][j][k][l][1]+dp[i][j][k][l][2]+dp[i][j][k][l][3];
			dp[i][j+1][k][l][1]+=dp[i][j][k][l][0]+dp[i][j][k][l][2]+dp[i][j][k][l][3];
			dp[i][j][k+1][l][2]+=dp[i][j][k][l][1]+dp[i][j][k][l][0]+dp[i][j][k][l][3];
			dp[i][j][k][l+1][3]+=dp[i][j][k][l][1]+dp[i][j][k][l][2]+dp[i][j][k][l][0];
		}
		return dp[a][b][c][d][0]+dp[a][b][c][d][1]+dp[a][b][c][d][2]+dp[a][b][c][d][3];
	}
};
