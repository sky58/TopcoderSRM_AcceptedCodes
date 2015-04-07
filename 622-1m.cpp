//SRM622DIV1-500 Ethernet
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
vector<pint> gr[58];
int d2[58][58];
int inf=114514,limit;
void dfs(int now){
  int n=gr[now].size();
  int dp[58][58];
  rep(i,55) rep(j,55) dp[i][j]=inf;dp[0][0]=0;
  rep(i,n){
    int ne=gr[now][i].fi,d=gr[now][i].se;
    dfs(ne);
    rep(j,55) rep(k,55){
      if(d+d2[ne][k]+dp[i][j]<=limit) dp[i+1][j+k]=min(dp[i+1][j+k],max(dp[i][j],d2[ne][k]+d));
      if(d2[ne][k]<=limit) dp[i+1][j+1+k]=min(dp[i+1][j+1+k],dp[i][j]);
    }
  }
  rep(i,55) d2[now][i]=dp[n][i];
}
class Ethernet{
  public:
  int connect(vector<int> a,vector<int> b,int L){
    int n=a.size()+1;
    rep(i,n-1) gr[a[i]].pb(mp(i+1,b[i]));
    limit=L;
    dfs(0);
    //rep(i,n) rep(j,n) cout<<i<<' '<<j<<' '<<d2[i][j]<<endl;
    rep(i,n){
      if(d2[0][i]<=limit) return i+1;
    }
    return n;
  }
};
