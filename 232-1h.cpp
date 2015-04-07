//SRM232DIV1-900 SalesPromotion
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
int po[55],co[55];
int dp[2][55][15500];
class SalesPromotion{
	public:
	int SalesPromotion::bestPrice(int a,int b,int c,vector <string> d){
		int n=d.size(),i,j,k,inf=1000000000,out=inf;
		for(i=0;i<n;i++){
			istringstream sin(d[i]);sin>>po[i]>>co[i];
		}
		for(i=0;i<55;i++) for(j=0;j<15500;j++) dp[0][i][j]=dp[1][i][j]=inf;dp[0][0][0]=0;
		for(i=0;i<n;i++){
			int now=i%2,next=(i+1)%2;
			for(j=0;j<55;j++) for(k=0;k<15500;k++) dp[next][j][k]=inf;
			for(j=0;j<=b;j++) for(k=0;k<=a;k++){
				dp[next][j][k]<?=dp[now][j][k]+(co[i]-co[i]*c/100);
				dp[next][j+1][k]<?=dp[now][j][k]+(co[i]-co[i]/2);
				if(k+po[i]<=a) dp[next][j][k+po[i]]<?=dp[now][j][k];
			}
		}
//		for(i=0;i<=b;i++) for(j=0;j<=a;j++) out<?=dp[n%2][i][j];return out;
		return dp[n%2][b][a];
	}
};
