//SRM535DIV1-1000 FoxAndGreed
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
int dp1[5010][110],dp2[5010][110],dp3[2510][110];
int mo=10007;
short co[5010][5010];
int zyo(int x,int y){
    int ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
int cal(int r,int d,int o,int s){
	int i,j,ret=0;
	rep(i,s+1) rep(j,s-i+1) ret=(ret+(dp1[r][i]*dp2[d][j])%mo*dp3[o][s-i-j])%mo;
	return ret;
}
class FoxAndGreed{
	public:
	int FoxAndGreed::count(int h,int w,int s){
		int i,j,k,out=0;
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(dp3,0,sizeof(dp3));
		dp1[0][0]=dp2[0][0]=dp3[0][0]=1;
		rep(i,w-1) rep(j,s+1){
			if(dp1[i][j]<1) continue;
			rep(k,s-j+1) dp1[i+1][j+k]=(dp1[i+1][j+k]+dp1[i][j]*(k+1))%mo;
		}
/*		REP(i,w-1,h+w-2) rep(j,s+1){
			if(dp1[i][j]<1) continue;
			rep(k,s-j+1) dp1[i+1][j+k]=(dp1[i+1][j+k]+dp1[i][j]*k)%mo;
		}
*/		rep(i,h-1) rep(j,s+1){
			if(dp2[i][j]<1) continue;
			rep(k,s-j+1) dp2[i+1][j+k]=(dp2[i+1][j+k]+dp2[i][j]*k)%mo;
		}
/*		REP(i,h-1,h+w-2) rep(j,s+1){
			if(dp2[i][j]<1) continue;
			rep(k,s-j+1) dp2[i+1][j+k]=(dp2[i+1][j+k]+dp2[i][j]*(k+1))%mo;
		}
*/		rep(i,2505) rep(j,s+1){
			if(dp3[i][j]<1) continue;
			rep(k,s-j+1) dp3[i+1][j+k]=(dp3[i+1][j+k]+dp3[i][j])%mo;
		}
		rep(i,5005){
			co[i][0]=co[i][i]=1;REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		if(h<2) return dp3[w-1][s];if(w<2) return dp3[h-1][s];
//		cout<<dp1[1][0]<<' '<<dp1[1][1]<<' '<<dp2[1][1]<<endl;
		rep(i,h-1){
			int r=w-1,d=i,o=h-1-i;
			int t=(zyo(s+1,w*h-2*(r+d)-1-o)*co[r+d-1][d])%mo;
//			cout<<t<<endl;
			out=(out+t*cal(r,d,o,s))%mo;
		}
		rep(i,w-1){
			int r=i,d=h-1,o=w-1-i;
			int t=(zyo(s+1,w*h-2*(r+d)-1-o)*co[r+d-1][d-1])%mo;
			out=(out+t*cal(r,d,o,s))%mo;
		}
		return out;
	}
};
