//SRM610DIV1-900 MiningGoldHard
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
vector<lint> x,y,nx,ny;
lint cal(int m,vector<int> a,vector<int> b){
  int n=a.size();
  reverse(All(a));if(n>0) reverse(All(b));b.pb(0);
  x.clear();y.clear();x.pb(0);x.pb(m);y.pb(0);y.pb(0);
  rep(i,n){
   nx.clear();ny.clear();
    nx.pb(x[0]);ny.pb(y[0]+m-(a[i]-x[0]));
    rep(j,y.size()-1){
      if(x[j]<a[i] && x[j+1]>a[i]){
        nx.pb(a[i]);ny.pb(m+(y[j+1]-y[j])/(x[j+1]-x[j])*(a[i]-x[j])+y[j]);
        nx.pb(x[j+1]);ny.pb(y[j+1]+m-(x[j+1]-a[i]));
      }
      else if(x[j+1]<=a[i]){
        nx.pb(x[j+1]);ny.pb(y[j+1]+m-(a[i]-x[j+1]));
      }
      else{
        nx.pb(x[j+1]);ny.pb(y[j+1]+m-(x[j+1]-a[i]));
      }
    }
    //cout<<i<<endl;rep(j,nx.size()) cout<<nx[j]<<' '<<ny[j]<<endl;
    int ma=0;
    rep(i,ny.size()){
      if(ny[ma]<ny[i]) ma=i;
    }
    if(b[i]==0){
    	x=nx;y=ny;continue;
    }
    if(ma<ny.size()-1 && ny[ma+1]==ny[ma]){
      x.clear();y=ny;
      rep(j,ma+1) x.pb(nx[j]-b[i]);
      REP(j,ma+1,ny.size()) x.pb(nx[j]+b[i]);
    }
    else{
      x.clear();y.clear();
      rep(j,ma+1){x.pb(nx[j]-b[i]);y.pb(ny[j]);}
      REP(j,ma,ny.size()){x.pb(nx[j]+b[i]);y.pb(ny[j]);}
    }
    //cout<<i<<endl;rep(j,x.size()) cout<<x[j]<<' '<<y[j]<<endl;
  }
  lint ret=0;
  rep(i,y.size()) ret=max(ret,y[i]);
  return ret;
}
class MiningGoldHard{
  public:
  int GetMaximumGold(int N,int M,vector<int> a,vector<int> b,vector<int> c,vector<int> d){
    lint f=cal(N,a,c),g=cal(M,b,d);
    //cout<<x<<' '<<y<<endl;
    return (int)f+g;
  }
};
