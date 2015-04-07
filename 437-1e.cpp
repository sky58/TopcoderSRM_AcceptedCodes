//SRM437DIV1-250 TheSwap
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
bool dp[12][1100000];
int kei(vector <int> a){
	int ret=0,i;
	for(i=0;i<a.size();i++){ret*=10;ret+=a[i];}
	return ret;
}

class TheSwap{
	public:
	int TheSwap::findMax(int a,int b){
		int i,j,k,l;memset(dp,false,sizeof(dp));
		dp[0][a]=true;
		
		for(i=0;i<b;i++) for(j=0;j<=1000000;j++){
			if(!dp[i][j]) continue;
			vector <int> c;int d=j;
			while(d>0){c.push_back(d%10);d/=10;}
			reverse(c.begin(),c.end());
			for(k=0;k<c.size()-1;k++) for(l=k+1;l<c.size();l++){
				vector <int> e=c;
				d=e[k];e[k]=e[l];e[l]=d;
				if(e[0]==0) continue;
				dp[i+1][kei(e)]=true;
			}
		}
		
		for(i=1000000;i>0;i--) if(dp[b][i]) return i;return -1;
	}
};
