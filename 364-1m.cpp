//SRM364DIV1-500 PowerPlants

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
int hen(char a){
	if(a<'A') return (a-'0');
	return ((a-'A')+10);
}
class PowerPlants{
	public:
	int PowerPlants::minCost(vector <string> a,string b,int c){
		int dp[(1<<16)];int n=a.size(),s=0,out=1000000,i,j,k;
		
		for(i=0;i<(1<<n);i++) dp[i]=1000000;
		for(i=0;i<n;i++){
			if(b[i]=='Y') s+=(1<<i);
		}
		dp[s]=0;
		
		for(i=0;i<(1<<n);i++){
			if(dp[i]>100000) continue;
			for(j=0;j<n;j++) for(k=0;k<n;k++){
				if(i&(1<<k)) continue;if(j==k) continue;
				if(i&(1<<j)){
					int t=i+(1<<k);
					dp[t]=min(dp[t],dp[i]+hen(a[j][k]));
				}
			}
		}
		for(i=0;i<(1<<n);i++){
			if(bitc(i)>=c) out=min(out,dp[i]);
		}
		return out;
	}
};
