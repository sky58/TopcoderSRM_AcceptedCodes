//SRM329DIV1-900 RPSChamps
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
double zyo[510],dp[510];
double con[510][510];
class RPSChamps{
	public:
	double RPSChamps::numberOfMoves(int a){
		int i,j;
		for(i=0;i<510;i++) for(j=0;j<510;j++) con[i][j]=0.0;
		con[0][0]=1.0;dp[1]=0.0;zyo[0]=1.0;
		for(i=1;i<505;i++) for(j=0;j<=i;j++){
			con[i][j]+=con[i-1][j];
			if(j>0) con[i][j]+=con[i-1][j-1];
		}
		for(i=1;i<505;i++) zyo[i]=zyo[i-1]/3.0;
		for(i=2;i<=a;i++){
			double kei=0.0,ret=1.0;
			for(j=1;j<i;j++){
				ret+=con[i][j]*(dp[j]+dp[i-j])*zyo[i-1];kei+=con[i][j]*zyo[i-1];
//				cout<<ret<<' '<<kei;
				dp[i]=ret/kei;
			}
		}
		return dp[a];
	}
};
