//SRM289DIV1-250 FallingBall
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
int dp[33][33][55];
int aru[33][33];
class FallingBall{
	public:
	int FallingBall::howMany(vector <string> a,int b){
		int i,j,k,x,y,n=a.size(),out=0;
		memset(dp,0,sizeof(dp));memset(aru,0,sizeof(aru));
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>x>>y;aru[x][y]++;
		}
		dp[0][0][aru[0][0]]=1;
		for(i=0;i<b-1;i++) for(j=0;j<=i;j++) for(k=0;k<=n;k++){
			dp[i+1][j][k+aru[i+1][j]]+=dp[i][j][k];dp[i+1][j+1][k+aru[i+1][j+1]]+=dp[i][j][k];
		}
		for(i=0;i<b;i++) out+=dp[b-1][i][n];return out;
	}
};
