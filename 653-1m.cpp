//SRM653DIV1-450 Singing
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
namespace MF{
  #define MAXN 25252
  #define MAXM 364364
  #define wint int
  const wint wEPS=0;
  const wint wINF=1001001001;
  int n,m,ptr[MAXN],next[MAXM],zu[MAXM];
  wint capa[MAXM],tof;
  int lev[MAXN],see[MAXN],que[MAXN],*qb,*qe;
  void init(int _n){
    n=_n;m=0;memset(ptr,~0,n*4);
  }
  void ae(int u,int v,wint w0,wint w1=0){
    next[m]=ptr[u];ptr[u]=m;zu[m]=v;capa[m]=w0;++m;
    next[m]=ptr[v];ptr[v]=m;zu[m]=u;capa[m]=w1;++m;
  }
  wint augment(int src,int ink,wint flo){
    if(src==ink) return flo;
    wint f;
    for(int &i=see[src];~i;i=next[i]) if(capa[i]>wEPS && lev[src]<lev[zu[i]]){
      if((f=augment(zu[i],ink,min(flo,capa[i])))>wEPS){
        capa[i]-=f;capa[i^1]+=f;return f;
      }
    }
    return 0;
  }
  bool solve(int src,int ink,wint flo=wINF){
    wint f;
    int i,u,v;
    for(tof=0;tof+wEPS<flo;){
      qb=qe=que;
      memset(lev,~0,n*4);
      for(lev[*qe++=src]=0,see[src]=ptr[src];qb!=qe;){
        for(i=ptr[u=*qb++];~i;i=next[i]) if(capa[i]>wEPS && !~lev[v=zu[i]]){
          lev[*qe++=v]=lev[u]+1;see[v]=ptr[v];
          if(v==ink) goto au;
        }
      }
      return 0;
    au:  for(;(f=augment(src,ink,flo-tof))>wEPS;tof+=f);
    }
    return 1;
  }
}
int gr[1010][1010];
int g2[1010][2];
int st[1010];
class Singing{
  public:
  int solve(int a,int b,int c,vector<int> d){
    int n=d.size(),out=0;
    memset(gr,0,sizeof(gr));
    memset(g2,0,sizeof(g2));
    /*rep(i,n){
      if(d[i]<b) st[i]=0;
      else if(d[i]>c) st[i]=1;
      else st[i]=-1;
    }
    rep(i,n-1){
      if(st[i]<0 && st[i+1]<0) gr[d[i]][d[i+1]]++,gr[d[i+1]][d[i]]++;
      else if(st[i]<0) g2[d[i]][st[i+1]]++;
      else if(st[i+1]<0) g2[d[i+1]][st[i]]++;
      else out+=abs(st[i]-st[i+1]);
      cout<<st[i]<<' '<<st[i+1]<<' '<<out<<endl;
    }*/
    rep(i,n-1){
     gr[d[i]][d[i+1]]++;gr[d[i+1]][d[i]]++;
    }
    int s=2005,t=s+1,v=t+1;
    MF::init(v);
    REP(i,0,1001) REP(j,i+1,1001){
      if(gr[i][j]>0) MF::ae(i,j,gr[i][j]),MF::ae(j,i,gr[i][j]);
    }
    REP(i,0,1001){
      //MF::ae(s,i,g2[i][1]);MF::ae(1001+i,t,g2[i][0]);
      if(i<b) MF::ae(s,i,114514);if(i>c) MF::ae(i,t,114514);
      //MF::ae(i,1001+i,114514);
    }
    MF::solve(s,t);
    return out+MF::tof;
  }
};
