//SRM624DIV1-450 DrivingPlans
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
int gr[2010][2010];
int mi[2010],m2[2010];
int inf=1000000010;
bool use[2010];
lint dp[2010];
lint mo=1000000009;
vector<pint> p;
class DrivingPlans{
  public:
  int count(int n,vector<int> a,vector<int> b,vector<int> c){
    rep(i,2010) rep(j,2010) gr[i][j]=inf;
    rep(i,a.size()){
      a[i]--;b[i]--;
      gr[a[i]][b[i]]=gr[b[i]][a[i]]=c[i];
      //if(a[i]==0 || b[i]==0) cout<<a[i]<<' '<<b[i]<<endl;
    }
    rep(i,2010) mi[i]=m2[i]=inf;mi[0]=0;
    rep(i,n){
      int it=-1;
      rep(j,n){
        if(m2[j]<inf) continue;
        if(it<0 || mi[it]>mi[j]) it=j;
      }
      //cout<<it<<' '<<mi[it]<<endl;
      m2[it]=mi[it];
      rep(j,n) mi[j]=min(mi[j],m2[it]+gr[it][j]);
    }
    //cout<<mi[1999]<<' '<<m2[1999]<<endl;
    rep(i,n) p.pb(mp(m2[i],i));sort(All(p));
    memset(use,false,sizeof(use));use[n-1]=true;
    for(int i=n-1;i>=0;i--){
      int it=p[i].se;
      rep(j,n){
        if(use[j] && gr[it][j]+m2[it]<=m2[j]) use[it]=true;
      }
      //if(use[it]) cout<<it<<endl;
    }
    rep(i,n) rep(j,n){
      if(use[i] && gr[i][j]==0) return -1;
    }
    memset(dp,0,sizeof(dp));dp[0]=1;
    rep(i,n){
      int it=p[i].se;
      if(!use[it]) continue;
      rep(j,n){
        if(gr[it][j]+m2[it]<=m2[j]) dp[j]=(dp[j]+dp[it])%mo;
      }
    }
    return (int)(dp[n-1]%mo);
  }
};
