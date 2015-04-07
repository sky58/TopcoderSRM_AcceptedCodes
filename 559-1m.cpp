//SRM559DIV1-500 HatRack
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
#define REP(i,a,b) for(i=a;i<b;i++) 
#define rep(i,n) REP(i,0,n) 
int f,dep,n; 
int le[55],ri[55],on[55],tw[55],ze[55]; 
vector <int> gr[55]; 
void dfs(int now,int pre,int nowd){ 
  if(now<=0 || now>n) return; 
  dep>?=nowd;int i; 
  rep(i,gr[now].size()){ 
    int t=gr[now][i];if(t==pre) continue; 
    if(le[now]==0) le[now]=t; 
    else if(ri[now]==0) ri[now]=t; 
    else f=0; 
    dfs(t,now,nowd+1); 
  } 
  return; 
} 
void dfs1(int now,int nowd){ 
  if(now<=0 || now>n) return; 
  if(nowd<dep-1 && ri[now]==0){f=0;return;} 
  //cout<<now<<' '<<nowd<<endl; 
  if(nowd==dep-1){ 
    if(le[now]==0) ze[now]++; 
    else if(ri[now]==0) on[now]++; 
    else tw[now]++; 
    return; 
  } 
  dfs1(le[now],nowd+1);dfs1(ri[now],nowd+1); 
  ze[now]=ze[ri[now]]+ze[le[now]];
  on[now]=on[ri[now]]+on[le[now]];
  tw[now]=tw[ri[now]]+tw[le[now]];
  return; 
} 
lint dfs2(int now,int nowd){ 
  if(now<=0 || now>n) return 0; 
  if(nowd==dep-1){ 
    if(ri[now]==0) return 1;return 2; 
  } 
  if(nowd<dep-1 && ri[now]==0) return 0; 
  if(on[now]>1) return 0;
  lint ret=0,re=dfs2(le[now],nowd+1)*dfs2(ri[now],nowd+1);
  if(on[le[now]]+tw[le[now]]<1 || on[ri[now]]+ze[ri[now]]<1) ret+=re;
  if(on[le[now]]+ze[le[now]]<1 || on[ri[now]]+tw[ri[now]]<1) ret+=re;
  return ret; 
} 
class HatRack{ 
  public: 
  long long HatRack::countWays(vector <int> a,vector <int> b){ 
    n=a.size()+1;int i,j;lint out=0; 
    rep(i,n-1){gr[a[i]].pb(b[i]);gr[b[i]].pb(a[i]);} 
    rep(i,n){
      memset(le,0,sizeof(le));memset(ri,0,sizeof(ri)); 
      memset(on,0,sizeof(on));memset(tw,0,sizeof(tw));memset(ze,0,sizeof(ze));
      dep=0;f=1;dfs(i+1,0,0);
      if(f==0) continue;
      dfs1(i+1,0); 
      if(f==0) continue;
      out+=f*dfs2(i+1,0);
    } 
    return out; 
  } 
};
