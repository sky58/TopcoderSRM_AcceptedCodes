//SRM253DIV1-500 AlphabetCount
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
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int dp[30][55][55];
class AlphabetCount{
	public:
	int AlphabetCount::count(vector <string> a,int b){
		int n=a.size(),m=a[0].size(),i,j,k,l,out=0,mo=1000000000;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='A') dp[1][i][j]=1;
		}
		for(i=1;i<b;i++) for(j=0;j<n;j++) for(k=0;k<m;k++) for(l=0;l<8;l++){
			int x=j+dx[l],y=k+dy[l];
			if(x<0 || x>=n || y<0 || y>=m) continue;
			if(a[x][y]==('A'+i)) dp[i+1][x][y]=min(mo,dp[i+1][x][y]+dp[i][j][k]);
		}
		for(i=0;i<n;i++) for(j=0;j<m;j++) out=min(mo,out+dp[b][i][j]);return out;
	}
};
