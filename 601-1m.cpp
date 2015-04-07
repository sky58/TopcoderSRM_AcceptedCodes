//SRM601DIV1-500 WinterAndSnowmen
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[2100][1050][2][2];
class WinterAndSnowmen{
	public:
	int getNumber(int n,int m){
		lint mo=1000000007,out=0;
		rep(i,11){
			memset(dp,0,sizeof(dp));dp[1][0][0][0]=1;
			REP(j,1,2010){
				int t=0;if((j&(1<<i))) t=1;
				rep(k,(1<<(10-i))) rep(l,2) rep(o,2){
					dp[j][k][l][o]%=mo;
					if(j<=n) dp[j+1][k^(j>>(i+1))][l^t][o]+=dp[j][k][l][o];
					if(j<=m) dp[j+1][k^(j>>(i+1))][l][o^t]+=dp[j][k][l][o];
					dp[j+1][k][l][o]+=dp[j][k][l][o];
				}
			}
			out=(out+dp[2010][0][0][1])%mo;
		}
		return (int)out;
	}
};
