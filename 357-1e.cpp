//SRM357DIV1-250 Hotel
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
#include<queue>
#include<deque>
using namespace std;
class Hotel{
	public:
	int Hotel::marketCost(int a,vector <int> b,vector <int> c){
		int dp[3010];int i,j,out=10000000;
		
		for(i=0;i<3010;i++) dp[i]=10000000;dp[0]=0;
		for(i=0;i<b.size();i++){
			int k=b[i];
			for(j=k;j<=3000;j++) dp[j]=min(dp[j],dp[j-k]+c[i]);
		}
		for(i=a;i<=3000;i++) out=min(out,dp[i]);
		return out;
	}
};
