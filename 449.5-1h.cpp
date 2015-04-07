//SRM449.5DIV1-900 PrefixFreeCode
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
int dp[510][55];
class PrefixFreeCode{
	public:
	int PrefixFreeCode::minCost(int n,vector <int> a){
		int i,j,k,m=a.size();
		sort(a.begin(),a.end());if(m==0) return a[0];
		for(i=0;i<510;i++) for(j=0;j<55;j++) dp[i][j]=1000000000;
		for(i=0;i<m;i++) dp[1][i]=a[i];dp[1][0]=0;for(i=0;i<=m;i++) dp[0][i]=0;
		for(i=2;i<=n;i++) for(j=0;j<m;j++) for(k=0;k<i;k++) dp[i][j]<?=dp[k][j+1]+dp[i-k][0]+a[j]*(i-k);
		return dp[n][0];
	}
};
