//SRM384DIV1-500 SchoolTrip

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

int bitc(int a){return a==0?0:a%2+bitc(a/2);}

class SchoolTrip{
	public:
	double SchoolTrip::duration(vector <int> a){
		double dp[100][6];int i,j,k,l,n=a.size();
		
		for(i=0;i<100;i++) for(j=0;j<6;j++) dp[i][j]=0.0;
		for(i=0;i<(1<<n);i++) if(bitc(i)>1) for(l=0;l<10000;l++) for(j=0;j<n;j++){
			int t=(j+1)%n;
			if(i&(1<<j)){
				double ret=10e6;
				for(k=0;k<n;k++)
				if(k!=j && i&(1<<k)) ret=min(ret,dp[i-(1<<k)][t]);
				dp[i][j]=ret*a[j]/100+dp[i][t]*(100-a[j])/100+1.0;
			}
			else dp[i][j]=dp[i][t];
		}
		return dp[(1<<n)-1][0];
	}
};
