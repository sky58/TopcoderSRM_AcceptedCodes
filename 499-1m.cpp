//SRM499DIV1-500 WhiteSpaceEditing
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
int dp[55][55][55];
class WhiteSpaceEditing{
	public:
	int WhiteSpaceEditing::getMinimum(vector <int> a){
		int i,j,k,l,m,n=a.size(),inf=1000000000,out=inf;
		for(i=0;i<55;i++) for(j=0;j<55;j++) for(k=0;k<55;k++) dp[i][j][k]=inf;
		for(i=0;i<n;i++) dp[i][i][i+1]=0;
		for(i=1;i<n;i++){
			for(j=0;i+j<=n;j++) for(k=0;k<n;k++) for(l=0;l<n;l++) dp[k][j][i+j]<?=dp[l][j][i+j]+abs(a[k]-a[l]);
			for(j=0;i+j<=n;j++){
				for(k=max(0,j-i);k<j;k++) for(l=0;l<n;l++) for(m=0;m<n;m++){
					dp[l][k][i+j]<?=min(dp[l][j][i+j]+dp[m][k][j]+abs(a[l]-a[m])+1,dp[m][j][i+j]+dp[l][k][j]+abs(a[l]-a[m])+1);
				}
				for(k=i+j;k<=n && k-(i+j)<=i;k++) for(l=0;l<n;l++) for(m=0;m<n;m++){
					dp[l][j][k]<?=min(dp[l][j][i+j]+dp[m][j+i][k]+abs(a[l]-a[m])+1,dp[m][j][i+j]+dp[l][i+j][k]+abs(a[l]-a[m])+1);
				}
			}
		}
		for(i=0;i<n;i++) out<?=dp[i][0][n]+a[i];return out;
	}
};
