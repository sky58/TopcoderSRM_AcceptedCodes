//SRM613DIV1-900 TaroCheckers
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
lint dp[210][55][55];
class TaroCheckers{
	public:
	int getNumber(vector<int> a,vector<int> b,int c){
		int n=a.size();lint mo=1000000007;
		memset(dp,0,sizeof(dp));dp[0][0][0]=1;
		rep(i,c){
			int okl=0,okr=0,jl=0;
			rep(j,n){
				if(c-b[j]<=i) okr++;
				if(a[j]-1>=i) okl++;
				if(a[j]-1==i) jl++;
			}
			//cout<<okr<<endl;
			rep(j,n+1) rep(k,n+1){
				dp[i][j][k]%=mo;//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
				if(n-(okl-jl)<=j){
					dp[i+1][j][k]+=dp[i][j][k]*(n-okl-okr+1);
					if(k<okr) dp[i+1][j][k+1]+=dp[i][j][k]*(okr-k);
				}
				if(n-(okl-jl)<=j+1){
					dp[i+1][j+1][k]+=dp[i][j][k]*(j+1-(n-okl));
				}
			}
		}
		return (int)(dp[c][n][n]%mo);
	}
};
