//SRM469DIV1-500TheMoviesLevelTwoDivOne
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
int dp[1100000],sc[1100000];
class TheMoviesLevelTwoDivOne{
	public:
	vector <int> TheMoviesLevelTwoDivOne::find(vector <int> a,vector <int> b){
		int n=a.size(),i,j,t=0;vector <int> out;
		memset(dp,0,sizeof(dp));for(i=0;i<1100000;i++) sc[i]=74;
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){if(i&(1<<j)) sc[i]+=47-a[j];}
		for(i=(1<<n)-1;i>=0;i--){
//			if(sc[i]<0) continue;
			for(j=0;j<n;j++){
				if(i&(1<<j)) continue;
				if(sc[i]>=b[j] && sc[i]+47>=a[j]) dp[i]>?=1+dp[i+(1<<j)];
			}
//			cout<<i<<' '<<dp[i]<<endl;
		}
		for(i=0;i<dp[0];i++){
			int ma=-10,mai=-1;
			for(j=0;j<n;j++){
				if(t&(1<<j)) continue;
				if(!(sc[t]>=b[j] && sc[t]+47>=a[j])) continue;
				if(ma<dp[t+(1<<j)]){ma=dp[t+(1<<j)];mai=j;}
			}
			out.pb(mai);t+=(1<<mai);
		}
		for(i=0;i<n;i++){if(!(t&(1<<i))) out.pb(i);}
		return out;
	}
};
