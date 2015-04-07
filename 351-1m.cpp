//SRM351DIV1-500 BoxesArrangement
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
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[53][53][53][6];
class BoxesArrangement{
	public:
	int BoxesArrangement::maxUntouched(string a){
		int inf=10000,i,j,k,l,n=a.size(),ak=0,bk=0,out=inf,m;
		for(i=0;i<53;i++) for(j=0;j<53;j++) for(k=0;k<53;k++) for(l=0;l<6;l++) dp[i][j][k][l]=inf;
		if(a[0]=='A') dp[1][1][0][0]=0;else dp[1][1][0][0]=1;
		if(a[0]=='B') dp[1][0][1][1]=0;else dp[1][0][1][1]=1;
		if(a[0]=='C') dp[1][0][0][2]=0;else dp[1][0][0][2]=1;
		for(i=0;i<n;i++){if(a[i]=='A') ak++;if(a[i]=='B') bk++;}
		for(i=1;i<n;i++) for(j=0;j<=i;j++) for(k=0;k+j<=i;k++) for(l=0;l<6;l++) for(m=0;m<3;m++){
//			cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k][0]<<' '<<dp[i][j][k][1]<<' '<<dp[i][j][k][2]<<endl;
			if(m+3==l) continue;
			int s=1,t=m;if(a[i]==(m+'A')) s=0;if(l==m) t=m+3;
			if(m==0) dp[i+1][j+1][k][t]<?=dp[i][j][k][l]+s;
			if(m==1) dp[i+1][j][k+1][t]<?=dp[i][j][k][l]+s;
			if(m==2) dp[i+1][j][k][t]<?=dp[i][j][k][l]+s;
		}
		for(i=0;i<6;i++) out<?=dp[n][ak][bk][i];if(out>=inf) return -1;return n-out;
	}
};
