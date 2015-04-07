//SRM530DIV1-900 GogoXBallsAndBins
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
lint dp[2][55][11000];
class GogoXBallsAndBins{
	public:
	int GogoXBallsAndBins::solve(vector <int> a,int b){
		int i,j,k,n=a.size(),mid=5500;lint mo=1000000009;
		rep(i,55) rep(j,11000) dp[0][i][j]=dp[1][i][j]=0;dp[0][0][mid]=1;
		rep(i,n){
			int now=i%2,next=(i+1)%2;
			rep(j,55) rep(k,11000) dp[next][j][k]=0;
			rep(j,52) rep(k,10700){
				if(dp[now][j][k]<1) continue;
				dp[next][j][k]=(dp[next][j][k]+(2*j+1)*dp[now][j][k])%mo;
				dp[next][j+1][k-2*a[i]]=(dp[next][j+1][k-2*a[i]]+dp[now][j][k])%mo;
				if(j>0){
					dp[next][j-1][k+2*a[i]]+=j*j*dp[now][j][k];
					dp[next][j-1][k+2*a[i]]%=mo;
				}
			}
		}
		return (int)(dp[n%2][0][mid+b*2])%mo;
	}
};
