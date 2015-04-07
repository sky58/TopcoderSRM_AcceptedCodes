//SRM597DIV1-900 LittleElephantAndBoard
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
typedef long long Int;
lint zyo[1100000],gya[1100000];
lint mo=1000000007;
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
lint con(int a,int b){
  if(a<0 || b<0 || b>a) return 0;
  return ((zyo[a]*gya[b])%mo*gya[a-b])%mo;
}
lint cal(int use,int r,int g,int b){
  int ur=(use+1)/2,ug=use/2;
  if(r<ur || g<ug) return 0;
  lint ret=(con(r-1,ur-1)*con(g-1,ug-1))%mo;
  //cout<<r-1<<' '<<ur-1<<' '<<g-1<<' '<<ug-1<<' '<<ret<<endl;
  b-=(r-ur+g-ug);if(b<0) return 0;
  //cout<<r<<g<<b<<ur<<ug<<ret<<con(b,ur+ug+1)<<endl;
  return (ret*con(ur+ug+1,b))%mo;
}
class LittleElephantAndBoard{
  public:
  int getNumber(int m,int r,int g,int b){
    r=m-r;g=m-g;b=m-b;
    zyo[0]=gya[0]=1;lint out=0;
    if(r<0 || g<0 || b<0) return 0;
    if(r<1){
      if(g==b) return 4;if(abs(g-b)<2) return 2;return 0;
    }
    if(g<1){
      if(r==b) return 4;if(abs(r-b)<2) return 2;return 0;
    }
    if(b<1){
      if(g==r) return 4;if(abs(g-r)<2) return 2;return 0;
    }
    rep(i,1050000) zyo[i+1]=(zyo[i]*(i+1))%mo;
    rep(i,1050000) gya[i]=invMod(zyo[i],mo);
    REP(i,2,m+1) out=(out+(cal(i,r,g,b)+cal(i,g,r,b))*2)%mo;
    return out;
  }
};
