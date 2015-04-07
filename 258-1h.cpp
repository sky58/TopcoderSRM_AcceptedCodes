//SRM258DIV1-1000 ChutesAndLadders
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int wa[150];double dp[10500][110],dp2[10500][110];
class ChutesAndLadders{
	public:
	vector <double> ChutesAndLadders::winningChance(vector <int> a,vector <int> b,vector <int> c){
		int i,j,k,l,n=c.size();vector <double> out;for(i=0;i<n;i++) out.pb(0.0);
		for(i=0;i<150;i++) wa[i]=i;for(i=0;i<a.size();i++) wa[a[i]]=b[i];
		for(i=0;i<110;i++) for(j=0;j<10500;j++) dp[j][i]=dp2[j][i]=0.0;dp[0][99]=1.0;
		for(i=1;i<10200;i++) for(j=0;j<99;j++) for(k=1;k<7;k++) for(l=1;l<7;l++){
			dp[i][j]+=dp[i-1][min(99,wa[j+k+l])]/36.0;
		}
//		for(i=0;i<100;i++) for(j=0;j<10;j++) cout<<i<<' '<<j<<' '<<dp[j][i]<<endl;
		for(i=10150;i>=0;i--) for(j=0;j<100;j++) dp2[i][j]=dp2[i+1][j]+dp[i][j];
		for(i=0;i<n;i++){
//			if(i==j) continue;
			for(k=1;k<10100;k++){
				double f=dp[k][c[i]];
				for(j=0;j<n;j++){
					if(i==j) continue;
//					if(i<j) out[i]+=dp[k][c[i]]*dp2[k][c[j]];else out[i]+=dp[k][c[i]]*dp2[k+1][c[j]];
					if(i<j) f*=dp2[k][c[j]];else f*=dp2[k+1][c[j]];
				}
				out[i]+=f;
			}
		}
		return out;
	}
};
