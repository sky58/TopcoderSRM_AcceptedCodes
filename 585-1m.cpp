//SRM585DIV1-500 LISNumber
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
lint dp[40][1300];
lint co[1300][1300];
class LISNumber{
	public:
	int count(vector <int> a,int b){
		int n=a.size(),sum=a[0];lint mo=1000000007;
		rep(i,1300){
			co[i][0]=co[i][i]=1;
			REP(j,1,i) co[i][j]=(co[i-1][j-1]+co[i-1][j])%mo;
		}
		memset(dp,0,sizeof(dp));dp[1][sum]=1;
		REP(i,1,n){
			rep(j,sum+1){
				if(dp[i][j]<1) continue;
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				rep(k,a[i]+1){
					if(k>j) continue;
					dp[i+1][j+a[i]-k]+=(dp[i][j]*co[j][k])%mo*co[sum-j+a[i]][a[i]-k];
					dp[i+1][j+a[i]-k]%=mo;
				}
			}
			sum+=a[i];
		}
		return (int)(dp[n][b]%mo);
	}
};
