//SRM430DIV1-500 TwinTowns
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
int dp[1100000];
int bitc(int a,int b){
	if(a==0) return 0;return bitc(a/b,b)+a%b;
}
class TwinTowns{
	public:
	vector <int> TwinTowns::optimalTwinTowns(vector <int> x,vector <int> y,int a,int b){
		int dis[12][12];int zyo[12];vector <int> out;out.push_back(0);out.push_back(100000);
		int i,j,k,n=x.size();
		
		zyo[0]=1;for(i=0;i<11;i++) zyo[i+1]=zyo[i]*(a+1);
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) dis[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
		for(i=1;i<1100000;i++) dp[i]=10000000;
		
		for(j=0;j<n-1;j++) for(k=j+1;k<n;k++) for(i=zyo[n]-1;i>=0;i--){
//			printf("%d %d %d\n",i,j,k);
			if(dis[j][k]<b) continue;
			if(i/zyo[j]%(a+1)==a || i/zyo[k]%(a+1)==a) continue;
			dp[i+zyo[j]+zyo[k]]<?=dp[i]+dis[j][k];
		}
		
		for(i=0;i<zyo[n];i++){
			int l=bitc(i,a+1)/2,m=dp[i];if(m==10000000) continue;
			if(out[0]<l || (out[0]==l && out[1]>m)){out[0]=l;out[1]=m;}
		}
		return out;
	}
};
