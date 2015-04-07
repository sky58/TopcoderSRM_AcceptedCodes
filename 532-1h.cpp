//SRM532DIV1-1000 DengklekCountingFormations
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
lint con[105][105][55];
lint dp[12][55][105][55];
lint mo=1000000007;
lint cal(int a,int b,int c,int d){
	if(dp[a][b][c][d]>=0) return dp[a][b][c][d];
	if(a<1) return 1;
	if(c==0){if(a<2 && b==0) return 1;return 0;}
	if(b==0){if(a<2) return 1;return 0;}
	if(d>b) return cal(a,b,c-1,1);
	int i;lint out=0;
	rep(i,a+1){
		lint ret=cal(i,b-d,c-1,1)*cal(a-i,b,c,d+1)%mo;
		ret=(ret*con[a][i][1])%mo;
		ret=(ret*con[b][d][i])%mo;
		out=(out+ret)%mo;
	}
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<out<<endl;
	return dp[a][b][c][d]=out;
}
class DengklekCountingFormations{
	public:
	int DengklekCountingFormations::numFormations(int n,int m,int t){
		int i,j,k,l;
		rep(i,105) rep(j,105) rep(k,55) con[i][j][k]=0;
		rep(i,105) rep(j,105) con[i][j][0]=1;
		rep(i,105){
			con[i][0][1]=con[i][i][1]=1;REP(j,1,i) con[i][j][1]=(con[i-1][j][1]+con[i-1][j-1][1])%mo;
		}
		rep(i,105) rep(j,105) REP(k,1,53) con[i][j][k+1]=(con[i][j][k]*con[i][j][1])%mo;
		rep(i,12) rep(j,55) rep(k,105) rep(l,55) dp[i][j][k][l]=-1;
		return cal(n,m,t,1);
	}
};
