//SRM248DIV1-500 ContractWork
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
int co[55][55];int dp[55][55][2];
class ContractWork{
	public:
	int ContractWork::minimumCost(vector <string> a,int n){
		int m=a.size(),inf=100000000,out=inf,i,j,k;
		//memset(dp,inf,sizeof(dp));
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j][0]=dp[i][j][1]=inf;
		for(i=0;i<m;i++){
			istringstream sin(a[i]);for(j=0;j<n;j++) sin>>co[j][i];
		}
		for(i=0;i<m;i++) dp[1][i][0]<?=co[0][i];
		
		for(i=1;i<n;i++) for(j=0;j<m;j++) for(k=0;k<m;k++){
			if(j!=k) dp[i+1][j][0]<?=min(dp[i][k][0],dp[i][k][1])+co[i][j];
			else dp[i+1][j][1]<?=dp[i][j][0]+co[i][j];
		}
		for(i=0;i<m;i++) out<?=min(dp[n][i][0],dp[n][i][1]);return out;
	}
};
