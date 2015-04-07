//SRM316DIV1-900 RoboRace
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
int dp[52][52][2502];
class RoboRace{
	public:
	int RoboRace::startTime(vector <string> a,vector <string> B){
		int i,j,k,h=a.size(),w=a[0].size(),n,gx,gy,yx,yy,fx,fy;
		string b;for(i=0;i<B.size();i++) b+=B[i];n=b.size();
//		cout<<n<<' '<<w<<' '<<h<<endl;
		for(i=0;i<52;i++) for(j=0;j<52;j++) for(k=0;k<2502;k++) dp[i][j][k]=10000;
//		cout<<n<<' '<<w<<' '<<h<<endl;
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(a[i][j]=='X'){gx=i;gy=j;}
			if(a[i][j]=='Y'){yx=i;yy=j;}
			if(a[i][j]=='F'){fx=i;fy=j;}
		}
		for(k=0;k<2502;k++) dp[gx][gy][k]=0;
//		cout<<n<<' '<<w<<' '<<h<<endl;
		for(i=n-1;i>=0;i--) for(j=0;j<h;j++) for(k=0;k<w;k++){
			dp[j][k][i]<?=dp[j][k][i+1]+1;
			if(b[i]=='N') if(j>0) if(a[j-1][k]!='#') dp[j][k][i]<?=dp[j-1][k][i+1]+1;
			if(b[i]=='S') if(j<h-1) if(a[j+1][k]!='#') dp[j][k][i]<?=dp[j+1][k][i+1]+1;
			if(b[i]=='W') if(k>0) if(a[j][k-1]!='#') dp[j][k][i]<?=dp[j][k-1][i+1]+1;
			if(b[i]=='E') if(k<w-1) if(a[j][k+1]!='#') dp[j][k][i]<?=dp[j][k+1][i+1]+1;
//			cout<<i<<' '<<j<<' '<<k<<' '<<dp[j][k][i]<<endl;
		}
		for(i=0;i<n;i++){
			if(dp[yx][yy][i]<dp[fx][fy][i]) return i;
		}
		return -1;
	}
};
