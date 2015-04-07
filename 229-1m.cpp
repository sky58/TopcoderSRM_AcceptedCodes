//SRM229DIV1-500BusinessPlan
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
int dp[230000];
vector <int> a,b,c;int n;
int kei(int in){
	if(dp[in]>-1) return dp[in];
	int ret=1000000,i;
	for(i=0;i<n;i++){
		if(b[i]>in) continue;
		ret=min(ret,c[i]+kei(in-b[i]+a[i]));
	}
	return dp[in]=ret;
}
class BusinessPlan{
	public:
	int BusinessPlan::howLong(vector <int> A,vector <int> B,vector <int> C,int sta,int goa){
		a=A;b=B;c=C;int i;n=a.size();int out=10000000;
		if(goa<=sta) return 0;
		int f=0;for(i=0;i<n;i++) if(a[i]<=sta) f=1;if(f==0) return -1;
		for(i=0;i<230000;i++) dp[i]=-1;for(i=0;i<=sta;i++) dp[i]=0;
		for(i=goa;i<=220000;i++) out=min(out,kei(i));
		return out;
	}
};
