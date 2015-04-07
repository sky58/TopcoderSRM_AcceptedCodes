//SRM635DIV1-1000 ColourHolic
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
lint dp[2][210][410][2];
lint co[50420][410];
lint num[410];
vector<lint> zyo;
class ColourHolic{
	public:
	int countSequences(vector<int> a){
		lint out=0,mo=1000000009;
		sort(All(a));
		zyo.pb(1);rep(i,410) zyo.pb((zyo[i]*2)%mo);
		memset(co,0,sizeof(co));memset(dp,0,sizeof(dp));memset(num,0,sizeof(num));
		rep(i,50415){
			co[i][0]=1;
			REP(j,1,min(410,i+1)) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		//cout<<co[2][1]<<endl;
		dp[1][0][1][0]=dp[0][1][1][1]=1;
		rep(i,a[0]+1){
			int now=(i&1),ne=(now^1);
			if(i>0) memset(dp[ne],0,sizeof(dp[ne]));
			rep(j,a[1]+1) rep(k,a[0]+a[1]+1){
				dp[now][j][k][0]%=mo;dp[now][j][k][1]%=mo;
				dp[now][j+1][k][1]+=dp[now][j][k][0];
				dp[ne][j][k][0]+=dp[now][j][k][1];
				dp[now][j+1][k+1][1]+=dp[now][j][k][0]+dp[now][j][k][1];
				dp[ne][j][k+1][0]+=dp[now][j][k][0]+dp[now][j][k][1];
			}
		}
		rep(i,a[0]+a[1]+1) num[i]=(dp[(a[0]&1)][a[1]][i][0]+dp[(a[0]&1)][a[1]][i][1])%mo;if(a[1]<1) num[0]=1;
		for(int i=a[3]-a[2];i<405;i+=2) for(int j=0;i+j<405;j++){
			int k=i+j,l=(a[2]+a[3]-(i+j*2))/2;if(k<1 || l<0) continue;
			lint t=((num[k-1]+num[k]*2+num[k+1])*zyo[j])%mo;
			t*=co[i][(i-a[3]+a[2])/2];t%=mo;
			t*=co[l+k-1][k-1];t%=mo;
			out=(out+t*co[i+j][i])%mo;
		}
		return (int)(out%mo);
	}
};
