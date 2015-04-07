//SRM528DIV1-1000 ColorfulCookie
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[55][1010];
class ColorfulCookie{
	public:
	int ColorfulCookie::getMaximum(vector <int> a,int b,int c){
		int hi=1005,lo=0,i,j,k,n=a.size();
		while(hi>lo){
			int mi=(hi+lo+1)/2;
			rep(i,55) rep(j,1010) dp[i][j]=-1;dp[0][0]=0;
			rep(i,n) rep(j,mi+1){
				if(dp[i][j]<0) continue;
				rep(k,a[i]/b+1) dp[i+1][min(mi,j+k)]>?=dp[i][j]+min(mi-k,(a[i]-b*k)/c);
			}
			if(dp[n][mi]>=mi) lo=mi;else hi=mi-1;
		}
		return (b+c)*lo;
	}
};
