//SRM592DIV1-500 LittleElephantAndPermutationDiv1
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
lint dp[52][52][2510];
class LittleElephantAndPermutationDiv1{
	public:
	int getNumber(int n,int m){
		lint out=0,mo=1000000007;
		memset(dp,0,sizeof(dp));dp[0][0][0]=1;
		rep(i,n) rep(j,n) rep(k,n*n+1){
			dp[i+1][j+1][k]+=dp[i][j][k];dp[i+1][j+1][k]%=mo;
			dp[i+1][j][k+i]+=(i-j+1)*dp[i][j][k];dp[i+1][j][k+i]%=mo;
			if(j>0){
				dp[i+1][j][k+i]+=(2*j)*(i-j+1)*dp[i][j][k];dp[i+1][j][k+i]%=mo;
				dp[i+1][j-1][k+i*2]+=j*j*(i-j+1)*(i-j+2)*dp[i][j][k];dp[i+1][j-1][k+i*2]%=mo;
			}
		}
		REP(i,m-n,n*n+1) out=(out+dp[n][0][i])%mo;return (int)out;
	}
};
