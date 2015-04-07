//SRM412DIV1-250 ForbiddenStrings

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;
long long dp[40][2];

class ForbiddenStrings{
	public:
	long long ForbiddenStrings::countNotForbidden(int n){
		int i;
		if(n==1) return 3;
		dp[2][0]=3;dp[2][1]=6;
		for(i=3;i<=n;i++){
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][1]=dp[i-1][0]*2+dp[i-1][1];
		}
		return dp[n][0]+dp[n][1];
	}
};
