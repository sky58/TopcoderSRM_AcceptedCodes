//SRM295DIV1-500 JimmyLightning
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
int dp[1100][55];
int dp2[1100][55];
vector <vector <pint> > di;vector <pint> cl;
class JimmyLightning{
	public:
	int JimmyLightning::robTheBank(vector <int> a,vector <string> b){
		int i,j,k,out=0,n=a.size(),v,t,r,l;
		memset(dp,-1,sizeof(dp));dp[0][0]=0;memset(dp2,0,sizeof(dp2));
		for(i=0;i<n+5;i++) di.pb(cl);
		for(i=0;i<b.size();i++){
			istringstream sin(b[i]);sin>>v>>t>>r;di[r].pb(mp(t,v));
		}
		for(i=0;i<=n;i++) for(j=0;j<1050;j++) for(k=0;k<di[i].size();k++){
			t=di[i][k].fi;v=di[i][k].se;if(j+t<=1070) dp2[j+t][i]>?=dp2[j][i]+v;
		}
//		for(i=0;i<=n;i++) for(j=0;j<10;j++) cout<<i<<' '<<j<<' '<<dp2[j][i]<<endl;
		for(i=0;i<1050;i++) for(l=0;l<2*n;l++){
			if(l>n) j=2*n-1-l;else j=l;
			if(dp[i][j]<0) continue;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			for(k=0;i+k<1050;k++){
				if(j>0) if(a[j-1]>i+k) dp[i+k][j-1]>?=dp[i][j]+dp2[k][j];
				if(j<n) if(a[j]>i+k) dp[i+k][j+1]>?=dp[i][j]+dp2[k][j];
			}
		}
		for(i=0;i<1070;i++) out>?=dp[i][0];return out;
	}
};
