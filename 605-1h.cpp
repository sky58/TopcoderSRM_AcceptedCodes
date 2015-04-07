//SRM605DIV1-1000 AlienAndPermutation
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
int l[210],r[210];
lint dp[202][202][202][2];
class AlienAndPermutation{
	public:
	int getNumber(vector<int> a,int b){
		int n=a.size();lint mo=1000000007;
		rep(i,n){
			l[i]=-1;r[i]=n;
			rep(j,i){
				if(a[j]>a[i]) l[i]=j;
			}
			REP(j,i+1,n){
				if(a[j]>a[i]) r[i]=min(r[i],j);
			}
		}
		memset(dp,0,sizeof(dp));dp[0][0][0][0]=1;
		rep(i,n+1) rep(j,n) rep(k,b+1){
			dp[i][j][k][0]%=mo;dp[i][j][k][1]%=mo;
			dp[i][j+1][k][0]+=dp[i][j][k][0]+dp[i][j][k][1];
			if(i<n && l[j]<i && i<r[j]){
				dp[i+1][j][k][1]+=dp[i][j][k][1];
				if(i==j) dp[i+1][j][k][0]+=dp[i][j][k][0];
				else dp[i+1][j][k+1][1]+=dp[i][j][k][0];
			}
		}
		lint out=0;rep(i,b+1) out+=dp[n][n][i][0]+dp[n][n][i][1];
		return (int)(out%mo);
	}
};
