//SRM398DIV1-500 CountPaths
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
int dp[55][55][55][55];
int ba[55][55];
class CountPaths{
	public:
	vector <int> CountPaths::difPaths(int x,int y,vector <int> cx, vector <int> cy){
		vector <int> out;
		int i,j,k,l,n=cx.size(),mo=1000007;
		
		for(i=0;i<n;i++) ba[cx[i]][cy[i]]=i+1;
		dp[0][1][0][0]=1;
		for(i=1;i<=x;i++) for(j=1;j<=y;j++){
//			if(i>30) cout<<i<<' '<<j<<'\n';
			if(ba[i][j]==0){
				for(k=0;k<=n;k++) for(l=0;l<=n;l++){
					dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][j][k][l])%mo;
					dp[i][j][k][l]=(dp[i][j][k][l]+dp[i][j-1][k][l])%mo;
				}
			}
			else{
				int t=ba[i][j];
				for(k=0;k<=n;k++) for(l=0;l<t;l++){
					dp[i][j][k+1][t]=(dp[i][j][k+1][t]+dp[i-1][j][k][l])%mo;
					dp[i][j][k+1][t]=(dp[i][j][k+1][t]+dp[i][j-1][k][l])%mo;
				}
			}
		}
		for(i=0;i<=n;i++) out.push_back(0);
		for(i=0;i<=n;i++) for(j=0;j<=n;j++) out[i]=(out[i]+dp[x][y][i][j])%mo;
		return out;
	}
};
