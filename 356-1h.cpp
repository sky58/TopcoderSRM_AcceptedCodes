//SRM356DIV1-950 EscapeTheJail
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
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
double dp[18][18];
class EscapeTheJail{
	public:
	double EscapeTheJail::findExit(vector <string> a){
		int n=a.size(),m=a[0].size(),sx,sy,i,j,k,l;double inf=1e7;
		for(i=0;i<18;i++) for(j=0;j<18;j++) dp[i][j]=inf;
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='$') dp[i][j]=0.0;if(a[i][j]=='@'){sx=i;sy=j;}
		}
		for(l=0;l<200000;l++) for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='#' || a[i][j]=='$') continue;double t=0.0;int s=0;
			for(k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];if(x<0 || x>=n || y<0 || y>=m) continue;
				if(a[x][y]=='#') continue;s++;t+=dp[x][y];
			}
			if(s>0) dp[i][j]=t/s+1.0;
		}
		if(dp[sx][sy]>=inf-1e6) return -1.0;return dp[sx][sy];
	}
};
