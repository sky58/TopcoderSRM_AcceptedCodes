//SRM305DIV1-500 InterleavePal
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
bool dp[53][53][53][53];
class InterleavePal{
	public:
	int InterleavePal::longestPal(string a,string b){
		int i,j,k,l,m=a.size(),n=b.size(),out=0;
		memset(dp,false,sizeof(dp));
		for(i=0;i<=m;i++) for(j=0;j<=m && j+i<=m;j++) for(k=0;k<=n;k++) for(l=0;l<=n && l+k<=n;l++){
			if(i+k<2) dp[i][j][k][l]=true;
			if(i>1) if(a[j]==a[j+i-1] && dp[i-2][j+1][k][l]) dp[i][j][k][l]=true;
			if(k>1) if(b[l]==b[l+k-1] && dp[i][j][k-2][l+1]) dp[i][j][k][l]=true;
			if(i*k>0) if(a[j]==b[l+k-1] && dp[i-1][j+1][k-1][l]) dp[i][j][k][l]=true;
			if(i*k>0) if(a[j+i-1]==b[l] && dp[i-1][j][k-1][l+1]) dp[i][j][k][l]=true;
			if(dp[i][j][k][l]) out>?=i+k;
		}
		return out;
	}
};