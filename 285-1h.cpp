//SRM285DIV1-1000 Distincter
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
int dp[55][1150][55];
class Distincter{
	public:
	int Distincter::disperse(vector <int> a,int b){
		int inf=100000000,n=a.size(),i,j,k,l,out=inf;
		sort(a.begin(),a.end());for(i=0;i<n;i++) a[i]+=55;
		for(i=0;i<55;i++) for(j=0;j<1150;j++) for(k=0;k<55;k++) dp[i][j][k]=inf;
		for(i=a[0]-52;i<=a[0]+52;i++) dp[1][i][1]=abs(i-a[0]);
		for(i=1;i<n;i++) for(j=0;j<1130;j++) for(k=1;k<55;k++){
			if(dp[i][j][k]>=inf) continue;
//			cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			for(l=max(j,a[i]-52);l<=max(j+1,a[i]);l++){
				if(l==j) dp[i+1][l][k]<?=dp[i][j][k]+abs(l-a[i]);
				else dp[i+1][l][k+1]<?=dp[i][j][k]+abs(l-a[i]);
			}
		}
		for(i=0;i<1150;i++) for(j=b;j<55;j++) out<?=dp[n][i][j];return out;
	}
};
