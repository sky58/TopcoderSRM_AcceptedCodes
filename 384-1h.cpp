//SRM384DIV1-1000 ChessTraining
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
int dp[110][110];bool sumi[300];
class ChessTraining{
	public:
	string ChessTraining::game(vector <int> x,vector <int> y){
		int i,n=x.size(),t=0,j,k;
		for(i=0;i<n;i++) if(x[i]==0 || y[i]==0 || x[i]==y[i]) return "Alice will win";
		for(i=1;i<105;i++) for(j=1;j<105;j++){
			if(i==j) continue;memset(sumi,false,sizeof(sumi));
			for(k=1;k<i;k++){if(k!=j) sumi[dp[k][j]]=true;}
			for(k=1;k<j;k++){if(k!=i) sumi[dp[i][k]]=true;}
			for(k=1;k<i && k<j;k++){sumi[dp[i-k][j-k]]=true;}
			for(k=0;k<300;k++){if(!sumi[k]) break;}dp[i][j]=k;
//			if(i<6 && j<6) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
		for(i=0;i<n;i++) t^=dp[x[i]][y[i]];
		if(t>0) return "Alice will win";return "Bob will win";
	}
};
