//SRM584DIV1-600 Excavations
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
lint dp[55][55];
lint co[55][55];
int x[55];
vector <int> dep;
class Excavations{
	public:
	long long Excavations::count(vector <int> a,vector <int> b,vector <int> c,int d){
		int n=a.size(),m=c.size();lint out=0;
		rep(i,53){
			co[i][0]=co[i][i]=1;
			REP(j,1,i) co[i][j]=co[i-1][j]+co[i-1][j-1];
		}
		dep.pb(110000);
		rep(i,n){
			int f=0;
			rep(j,m){
				if(a[i]==c[j]) f=1;
			}
			if(f<1){
				a[i]=-1;dep.pb(b[i]);
			}
		}
		sort(All(dep));dep.erase(unique(All(dep)),dep.end());
		rep(i,dep.size()){
			memset(x,0,sizeof(x));
			int ok=0,ok2=0;
			rep(k,n){
				if(b[k]<dep[i]){
					rep(j,m){
						if(a[k]==c[j]){
							x[j]++;
						}
					}
				}
				else{
					ok++;if(b[k]==dep[i] && a[k]<0) ok2++;
				}
			}
			memset(dp,0,sizeof(dp));dp[0][0]=1;
			rep(j,m) rep(k,d+1) REP(l,1,x[j]+1){
				//lint w=co[x[j]][l],z=co[x[j]-y[j]][l];
				//dp[j+1][k+l][1]+=dp[j][k][1]*w+dp[j][k][0]*(w-z);
				dp[j+1][k+l]+=dp[j][k]*co[x[j]][l];
			}
			if(dep[i]>105000) out+=dp[m][d];
			else{
				rep(j,min(d,ok)+1){
					out+=dp[m][d-j]*(co[ok][j]-co[ok-ok2][j]);
				}
			}
			//cout<<out<<endl;
		}
		return out;
	}
};
