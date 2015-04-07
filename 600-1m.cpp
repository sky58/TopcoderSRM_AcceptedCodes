//SRM600DIV1-600 PalindromeMatrix
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
int on[20],tw[20],dp[20];
class PalindromeMatrix{
	public:
	int minChange(vector<string> a,int b,int c){
		int n=a.size(),m=a[0].size(),out=n*m;
		rep(i,(1<<n)){
			if(__builtin_popcount(i)!=b) continue;
			int ret=0;
			rep(j,n){
				if(!(i&(1<<j))) continue;
				rep(k,m/2){
					if(a[j][k]!=a[j][m-k-1]) ret++;
				}
			}
			memset(on,0,sizeof(on));memset(tw,0,sizeof(tw));
			rep(j,m) rep(k,n/2){
				if(a[k][j]!=a[n-1-k][j]){
					int s=(i&(1<<k)),t=(i&(1<<(n-1-k)));
					if(s>0 && t>0){
						if(a[k][j]==a[k][m-1-j] && a[n-1-k][j]==a[n-1-k][m-1-j]) on[j]+=2;
					}
					else if(s>0){
						if(a[k][j]==a[k][m-1-j]) on[j]++;
					}
					else if(t>0){
						if(a[n-1-k][j]==a[n-1-k][m-1-j]) on[j]++;
					}
					else on[j]++;
				}
			}
			rep(j,m/2) rep(k,n/2){
				int s=(i&(1<<k)),t=(i&(1<<(n-1-k)));
				if(s>0 && t>0){
					if(a[k][j]==a[k][m-1-j] && a[n-1-k][j]==a[n-1-k][m-1-j] && a[k][j]!=a[n-1-k][j]) tw[j]+=2;
				}
				else if(s>0){
					if(a[n-1-k][j]!=a[n-1-k][m-1-j]) tw[j]++;
					if(a[k][j]==a[k][m-1-j] && a[n-1-k][j]==a[n-1-k][m-1-j] && a[k][j]!=a[n-1-k][j]) tw[j]+=2;
				}
				else if(t>0){
					if(a[k][j]!=a[k][m-1-j]) tw[j]++;
					if(a[k][j]==a[k][m-1-j] && a[n-1-k][j]==a[n-1-k][m-1-j] && a[k][j]!=a[n-1-k][j]) tw[j]+=2;
				}
				else{
					if(a[k][j]!=a[n-1-k][j]) tw[j]++;
					if(a[k][m-1-j]!=a[n-1-k][m-1-j]) tw[j]++;
				}
			}
			rep(j,20) dp[j]=1000;dp[0]=0;
			rep(j,m/2) for(int k=15;k>=0;k--){
				dp[k+2]=min(dp[k+2],dp[k]+tw[j]);
				dp[k+1]=min(dp[k+1],dp[k]+min(on[j],on[m-1-j]));
			}
			//cout<<ret<<' '<<dp[c]<<endl;
			/*if(ret+dp[c]<14){
				rep(j,n) cout<<((i>>j)&1);cout<<' '<<ret<<' '<<dp[c]<<endl;
				rep(j,m) cout<<on[j]<<' ';cout<<endl;rep(j,m/2) cout<<tw[j]<<' ';cout<<endl;
			}*/
			out=min(out,ret+dp[c]);
		}
		return out;
	}
};
