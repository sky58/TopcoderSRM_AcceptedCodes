//SRM256DIV1-1000 ImageRepeat
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
short dp[53][53][53][53][3];
class ImageRepeat{
	public:
	int ImageRepeat::largestSize(vector <string> a,vector <string> b){
		int i,j,k,l,n=a.size(),m=a[0].size(),n1=b.size(),m1=b[0].size(),out=0;
		memset(dp,0,sizeof(dp));
		for(i=n-1;i>=0;i--) for(j=m-1;j>=0;j--) for(k=n1-1;k>=0;k--) for(l=m1-1;l>=0;l--){
			if(a[i][j]!=b[k][l]) continue;
			dp[i][j][k][l][0]=dp[i+1][j][k+1][l][0]+1;
			dp[i][j][k][l][1]=dp[i][j+1][k][l+1][1]+1;
			dp[i][j][k][l][2]=min(min((int)dp[i][j][k][l][0],(int)dp[i][j][k][l][1]),(int)dp[i+1][j+1][k+1][l+1][2]+1);
			out>?=dp[i][j][k][l][2];
		}
		return out;
	}
};
