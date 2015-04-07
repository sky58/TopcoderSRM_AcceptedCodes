//SRM309DIV1-600 KMonotonic
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
int ka[55][110];
int dp[55][110][55][2];
class KMonotonic{
	public:
	int KMonotonic::transform(vector <int> a,int b){
		int n=a.size(),inf=1900000000,i,j,k,l,out=inf;
		for(i=0;i<55;i++) for(j=0;j<110;j++) for(k=0;k<55;k++){dp[i][j][k][0]=dp[i][j][k][1]=inf;}
		for(i=0;i<n;i++) for(j=0;j<n;j++){ka[i][j]=a[j]+(i-j);ka[i][j+n]=a[j]+(j-i);}
		for(i=0;i<2*n;i++){
			dp[0][i][1][0]=abs(a[0]-ka[0][i]);dp[0][i][1][1]=abs(a[0]-ka[0][i]);
		}
		for(i=0;i<n-1;i++) for(j=0;j<2*n;j++) for(k=1;k<=b;k++){
			if(dp[i][j][k][0]>=inf && dp[i][j][k][1]>=inf) continue;
			for(l=0;l<2*n;l++){
				if(ka[i+1][l]>ka[i][j]) dp[i+1][l][k][0]<?=dp[i][j][k][0]+abs(a[i+1]-ka[i+1][l]);
				if(ka[i+1][l]<ka[i][j]) dp[i+1][l][k][1]<?=dp[i][j][k][1]+abs(a[i+1]-ka[i+1][l]);
				dp[i+1][l][k+1][0]<?=dp[i][j][k][0]+abs(a[i+1]-ka[i+1][l]);
				dp[i+1][l][k+1][0]<?=dp[i][j][k][1]+abs(a[i+1]-ka[i+1][l]);
				dp[i+1][l][k+1][1]<?=dp[i][j][k][0]+abs(a[i+1]-ka[i+1][l]);
				dp[i+1][l][k+1][1]<?=dp[i][j][k][1]+abs(a[i+1]-ka[i+1][l]);
			}
		}
		for(j=0;j<2*n;j++) for(k=1;k<=b;k++){out<?=dp[n-1][j][k][0];out<?=dp[n-1][j][k][1];}
		return out;
	}
};
