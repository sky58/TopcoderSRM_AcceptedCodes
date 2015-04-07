//SRM370DIV1-500 ConnectTheCities
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
class ConnectTheCities{
	public:
	int ConnectTheCities::minimalRange(int a,int b,vector <int> c){
		int i,j,k,l,n=c.size();sort(c.begin(),c.end());
		for(i=1;i<a;i++){
			int dp[55][110];for(j=0;j<55;j++) for(k=0;k<110;k++) dp[j][k]=1000000;
			dp[0][0]=0;
			for(j=0;j<n;j++) for(k=0;k<=a;k++) for(l=0;l<=i;l++) dp[j+1][k+l]<?=(dp[j][k]+abs(c[j]-k-l));
			int t=1000000;for(j=0;j<=i;j++) t<?=dp[n][a-j];
			if(t<=b) return i;
		}
		return a;
	}
};
