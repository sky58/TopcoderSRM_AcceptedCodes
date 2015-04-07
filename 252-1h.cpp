//SRM252DIV1-1000 WordBoggle
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
int dy[4]={1,-1,0,0},dx[4]={0,0,1,-1};
int dp[(1<<16)+10][5][5];
double dp2[(1<<16)+10];
int bitc[(1<<16)+10];
int ke[10];int ma[10][20];
class WordBoggle{
	public:
	double WordBoggle::expectedScore(vector <string> a,vector <string> b){
		int i,j,k,l,n;double out=0.0;vector <double> zyo;
		zyo.pb(1.0);for(i=1;i<20;i++) zyo.pb(zyo[i-1]*i);
		for(i=0;i<(1<<16);i++) bitc[i]=__builtin_popcount(i);
		memset(dp,0,sizeof(dp));memset(ke,0,sizeof(ke));
		for(i=0;i<4;i++) for(j=0;j<4;j++) dp[(1<<(i*4+j))][i][j]=1;
		for(i=0;i<(1<<16);i++) for(k=0;k<4;k++) for(l=0;l<4;l++){
			if(dp[i][k][l]<1) continue;
			for(j=0;j<4;j++){
				int x=k+dx[j],y=l+dy[j];if(x<0 || x>3 || y<0 || y>3) continue;
				if(!(i&(1<<(x*4+y)))) dp[i+(1<<(x*4+y))][x][y]+=dp[i][k][l];
			}
		}
		for(i=0;i<(1<<16);i++) for(j=0;j<4;j++) for(k=0;k<4;k++) ke[bitc[i]]+=dp[i][j][k];
		bitc[0]=0;
		for(i=0;i<b.size();i++){
			for(j=0;j<(1<<16)+10;j++) dp2[j]=0.0;dp2[0]=1.0;n=b[i].size();double ret=0.0;
			memset(ma,0,sizeof(ma));
			for(j=0;j<n;j++) for(k=0;k<16;k++) for(l=0;l<6;l++){if(b[i][j]==a[k][l]) ma[j][k]++;}
			for(j=0;j<(1<<16);j++){
//				cout<<j<<' '<<bitc[j]<<endl;
				if(bitc[j]>=n){if(bitc[j]==n) ret+=dp2[j];continue;}
				for(k=0;k<16;k++){
					if(!(j&(1<<k))) dp2[j+(1<<k)]+=dp2[j]*ma[bitc[j]][k]/6.0;
				}
			}
			out+=ret*n*n*ke[n]*zyo[16-n];
		}
		return out/zyo[16];
	}
};
