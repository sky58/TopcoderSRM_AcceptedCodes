//SRM601DIV1-950 WinterAndShopping
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
vector <int> op[510];
lint co[510][510];
lint dp[510][110][110];
int st[55],go[55];
lint mo=1000000007;
class WinterAndShopping{
	public:
	int getNumber(vector <int> s,vector <int> r,vector <int> g,vector <int> b){
		int n=s.size();
		rep(i,510){
			co[i][0]=co[i][i]=1;
			REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		rep(i,n){
			st[i]=s[i]-1;go[i]=st[i]+r[i]+g[i]+b[i];
			REP(j,st[i],go[i]) op[j].pb(i);
		}
		REP(i,1,510){
			if(op[i].size()>1 && st[op[i][0]]>st[op[i][1]]) reverse(All(op[i]));
		}
		//rep(i,2) cout<<op[i+1][0]<<' '<<op[i+1][1]<<endl;
		dp[0][0][0]=1;
		rep(i,505){
			if(op[i].size()==0){
				dp[i+1][0][0]=dp[i][0][0];
			}
			if(op[i].size()==1){
				int sh=op[i][0];
				rep(j,101) rep(k,101){
					if(j+k>i-st[sh]) continue;
					dp[i][j][k]%=mo;
					dp[i+1][j][k]+=dp[i][j][k];
					dp[i+1][j+1][k]+=dp[i][j][k];
					dp[i+1][j][k+1]+=dp[i][j][k];
				}
				if(i+1==go[sh]) dp[i+1][0][0]=dp[i+1][r[sh]][g[sh]];
			}
			if(op[i].size()==2){
				int s1=op[i][0],s2=op[i][1],ne=min(go[s1],go[s2]);
				if(go[s1]<go[s2]){
					rep(j,101) rep(k,101){
						if(j+k>i-st[s1]) continue;
						int nr=r[s1]-j,ng=g[s1]-k;
						if(nr<0 || ng<0 || nr+ng>ne-i) continue;
						dp[ne][nr][ng]=((dp[i][j][k]*co[ne-i][nr])%mo*co[ne-i-nr][ng])%mo;
					}
				}
				else{
					rep(j,101) rep(k,101){
						if(j+k>i-st[s1]) continue;
						int nr=r[s2]+j,ng=g[s2]+k;
						if(nr>r[s1] || ng>g[s1]) continue;
						dp[ne][nr][ng]=((dp[i][j][k]*co[ne-i][r[s2]])%mo*co[ne-i-r[s2]][g[s2]])%mo;
					}
					if(go[s1]==go[s2]) dp[ne][0][0]=dp[ne][r[s1]][g[s1]];
				}
				i=ne-1;
			}
		}
		return (int)(dp[502][0][0]%mo);
	}
};
