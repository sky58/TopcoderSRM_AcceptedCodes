//SRM614DIV1-525 CycleColoring
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
lint dp[1000010][2];
lint d2[110][2];
lint mo=1000000007;
lint zyo(lint x,lint y){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
class CycleColoring{
	public:
	int countColorings(vector<int> a,vector<int> from,vector<int> to,int d){
		lint inv=zyo(d-1,mo-2);
		//cout<<(inv*(d-1))%mo<<endl;
		int n=a.size(),b=to[n-1];
		for(int i=n-1;i>0;i--) to[i]=to[i-1];to[0]=b;
		memset(dp,0,sizeof(dp));dp[0][0]=1;
		rep(i,1000005){
			dp[i+1][0]=dp[i][1];
			dp[i+1][1]=(dp[i][0]*(d-1)+dp[i][1]*(d-2))%mo;
		}
		memset(d2,0,sizeof(d2));d2[0][0]=d;
		rep(i,n){
			d2[i][0]%=mo;d2[i][1]%=mo;
			//cout<<i<<' '<<d2[i][0]<<' '<<d2[i][1]<<endl;
			int x=(from[i]+a[i]-to[i])%a[i],y=a[i]-x;//cout<<a[i]<<' '<<from[i]<<' '<<to[i]<<endl;
			lint same=(dp[x][0]*dp[y][0])%mo,diff=((dp[x][1]*dp[y][1])%mo*((inv*inv)%mo))%mo;
			d2[i+1][0]+=d2[i][0]*same+d2[i][1]*diff;
			d2[i+1][1]+=(d2[i][0]*diff)%mo*(d-1)+d2[i][1]*same+(d2[i][1]*diff)%mo*(d-2);
		}
		return (int)(d2[n][0]%mo);
	}
};
