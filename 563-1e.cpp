//SRM563DIV1-300 FoxAndHandle
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
int num[30],now[30],cal[30];
class FoxAndHandle{
  public:
  string FoxAndHandle::lexSmallestName(string a){
    int n=a.size(),i,j,it=-1,k;string out="";
    memset(num,0,sizeof(num));
    memset(now,0,sizeof(now));
    rep(i,n) num[(a[i]-'a')]++;
    while(out.size()<n/2){
      rep(i,26){
        int f=0;
        memset(cal,0,sizeof(cal));
        if(now[i]*2>=num[i]) continue;
        REP(j,it+1,n){
          if((a[j]-'a')==i) break;
        }
        rep(k,j) cal[(a[k]-'a')]++;
        rep(k,26){
          if(cal[k]-now[k]>num[k]/2) f=1;
        }
        if(f<1){out+=('a'+i);now[i]++;it=j;break;}
      }
    }
    return out;
  }
};
