//SRM261DIV1-1000 StackingBoxes
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
#define se second.first
#define th second.second
typedef pair<int,int> pint;
typedef pair<int,pint> tint;
int dp[1300][1300];
int inf=1900000000;
class StackingBoxes{
	public:
	int StackingBoxes::highestStack(vector <string> a,vector <string> b){
		vector <int> x,y;vector <tint> z;int i,j,t;
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);while(sin>>t) x.pb(t);
		}
		for(i=0;i<b.size();i++){
			istringstream sin(b[i]);while(sin>>t) y.pb(t);
		}
		int n=x.size();for(i=0;i<n;i++) z.pb(mp(x[i]+y[i],mp(x[i],y[i])));sort(z.begin(),z.end());
		for(i=0;i<1300;i++) for(j=0;j<1300;j++) dp[i][j]=inf;dp[0][0]=0;
//		for(i=0;i<n;i++) cout<<z[i].fi<<' '<<z[i].se<<' '<<z[i].th<<endl;
		for(i=0;i<n;i++) for(j=0;j<=i;j++){
			if(dp[i][j]<=z[i].th) dp[i+1][j+1]<?=dp[i][j]+z[i].se;dp[i+1][j]<?=dp[i][j];
		}
		for(i=n;i>=0;i--){if(dp[n][i]<inf) return i;}
	}
};
