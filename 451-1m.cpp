//SRM451DIV1-500 BaronsAndCoins
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
int inf=1000000000;
int dp[55][55];
class BaronsAndCoins{
	public:
	int BaronsAndCoins::getMaximum(vector <int> x,vector <int> y){
		vector <pint> t;int out=0,i,j,k,n=x.size();
		for(i=0;i<n;i++) t.pb(mp(y[i],x[i]));t.pb(mp(0,0));
		sort(t.begin(),t.end());
//		for(i=0;i<n;i++) cout<<t[i].fi<<' '<<t[i].se<<'\n';
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=inf;dp[0][0]=0;
		for(i=0;i<n;i++) for(j=0;j<=i;j++) for(k=i+1;k<=n;k++){
			int dx=t[k].se-t[i].se,dy=t[k].fi-t[i].fi,s=dp[i][j];
			if(dy==0 || dp[i][j]==inf) continue;
//			if(k==n) cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';		
			dx-=dy*(dy+1)/2;if(dx<dy*s) continue;
			dp[k][j+1]<?=(dx-1+dy)/dy+dy;
		}
		for(i=0;i<=n;i++) for(j=0;j<=n;j++){
			if(dp[j][i]<inf) out>?=i;
		}
		return out;
	}
};
