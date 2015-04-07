//SRM579DIV1-450 TravellingPurchasingMan
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
int dp[(1<<16)+10][20];
int op[55],cl[55],du[55];
int ed[55][55];
class TravellingPurchasingMan{
  public:
  int TravellingPurchasingMan::maxStores(int n,vector <string> a,vector <string> b){
    int m=a.size(),inf=400000000,out=0,x,y,z;
    rep(i,n) rep(j,n) ed[i][j]=inf;rep(i,n) ed[i][i]=0;
    rep(i,b.size()){
      istringstream sin(b[i]);
      sin>>x>>y>>z;ed[x][y]<?=z;ed[y][x]<?=z;
    }
    rep(k,n) rep(i,n) rep(j,n) ed[i][j]<?=ed[i][k]+ed[k][j];
    
    rep(i,m){
      istringstream sin(a[i]);
      sin>>op[i]>>cl[i]>>du[i];
    }
    
    rep(i,(1<<m)) rep(j,m) dp[i][j]=inf;
    rep(i,m) dp[0][i]<?=ed[n-1][i];
    rep(i,(1<<m)) rep(j,m){
      if(dp[i][j]>=inf) continue;
      //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
      rep(k,m){
        if((i&(1<<k))) continue;
        if(ed[j][k]+dp[i][j]<=cl[k]) dp[i+(1<<k)][k]<?=max(op[k],dp[i][j]+ed[j][k])+du[k];
      }
    }
    rep(i,(1<<m)) rep(j,m){
      if(dp[i][j]<inf){
        out>?=__builtin_popcount(i);
      }
    }
    return out;
  }
};
