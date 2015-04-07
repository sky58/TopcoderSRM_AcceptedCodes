//SRM582DIV1-600 ColorfulBuilding
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
lint dp[1300][1300][2];
lint zyo[1300][1300];
int nex[1300];
class ColorfulBuilding{
	public:
	int count(vector <string> a,vector <string> b,int c){
		string x="",y="";lint mo=1000000009;
		rep(i,a.size()) x+=a[i];rep(i,b.size()) y+=b[i];
		reverse(All(x));reverse(All(y));int n=x.size();
		memset(nex,-1,sizeof(nex));
		rep(i,n){
			REP(j,i+1,n){
				if(x[i]==x[j] && y[i]==y[j]){nex[i]=j;break;}
			}
		}
		rep(i,1300){
			zyo[i][i]=max(1,i);if(i>0) zyo[i][i-1]=1;
			REP(j,i,1300) zyo[i][j+1]=(zyo[i][j]*(j+1))%mo;
		}
		memset(dp,0,sizeof(dp));dp[0][0][0]=1;
		//rep(i,n) cout<<nex[i]<<endl;
		rep(i,n) rep(j,c+1){
			lint j1=(dp[i][j][0]+mo-dp[i][j][1])%mo,j0=(dp[i][j][1]*(i+1))%mo;
			//cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
			if(nex[i]>=0){
				dp[nex[i]][j+1][1]=(dp[nex[i]][j+1][1]+j1*zyo[i+1][nex[i]-1])%mo;
				dp[nex[i]][j][1]=(dp[nex[i]][j][1]+j0*zyo[i+1][nex[i]-1])%mo;
			}
			dp[i+1][j+1][0]=(dp[i+1][j+1][0]+j1)%mo;
			dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0]*i+dp[i][j][1])%mo;
		}
		return (int)(dp[n][c][0])%mo;
	}
};
