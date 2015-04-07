//SRM383DIV1-500 FloorBoards
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
int dp[110][1100];
class FloorBoards{
	public:
	int FloorBoards::layout(vector <string> a){
		int i,j,n=a.size(),m=a[0].size(),out=1000;
		for(i=0;i<110;i++) for(j=0;j<1100;j++) dp[i][j]=1000;dp[0][0]=0;
		
		for(i=0;i<n*m;i++) for(j=0;j<(1<<n);j++){
			if(dp[i][j]>500) continue;
			int x=i%n,y=i/n,t;
			if(a[x][y]=='#'){dp[i+1][(j|(1<<x))-(1<<x)]<?=dp[i][j];continue;}
			if(j&(1<<x)) t=0;else t=1;dp[i+1][j|(1<<x)]<?=dp[i][j]+t;
			if(x>0 && a[x-1][y]!='#' && !(j&(1<<(x-1)))) t=0;else t=1;
			dp[i+1][(j|(1<<x))-(1<<x)]<?=dp[i][j]+t;
		}
		for(i=0;i<(1<<n);i++) out<?=dp[n*m][i];
		return out;
	}
};
