//SRM587DIV1-900 ThreeColorbility
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
int n,m,f;
int st[55];
vector <pint> ed[55];
void dfs(int a,int b){
	//cout<<a<<' '<<st[a]<<' '<<b<<endl;
	if(st[a]>=0){
		if(st[a]!=b) f=0;return;
	}
	st[a]=b;
	rep(i,ed[a].size()) dfs(ed[a][i].fi,(b+ed[a][i].se)%2);
	return;
}
bool can(vector <string> a){
	memset(st,-1,sizeof(st));
	rep(i,n) ed[i].clear();
	rep(i,n) rep(j,n) rep(k,m){
		if(a[i][k]==a[j][k] && a[i][k]!='?') ed[i].pb(mp(j,0));
		if(a[i][k]!=a[j][k] && a[i][k]!='?' && a[j][k]!='?') ed[i].pb(mp(j,1));
	}
	f=1;
	rep(i,n){
		if(st[i]<0) dfs(i,0);
	}
	if(f>0) return true;return false;
}
char che(char a,int b){
  if(b==1) return a;
  if(a=='N') return 'Z';return 'N';
}
class ThreeColorability{
  public:
  vector <string> lexSmallest(vector <string> a){
    n=a.size();m=a[0].size();vector <string> ret;
    if(!can(a)) return ret;
    ret=a;
    rep(i,m){
      if(a[0][i]!='Z'){
        ret[0][i]='N';if(can(ret)) ret[0][i]='N';else ret[0][i]='Z';
      }
      else ret[0][i]='Z';
    }
    REP(i,1,n){
      int t=3;
      rep(j,m){
        if(ret[i][j]=='?') continue;
        if(ret[i][j]==ret[0][j]) t&=1;else t&=2;
      }
      if(t==3){
        if(ret[0][0]=='N') t=1;else t=2;
      }
      rep(j,m) ret[i][j]=che(ret[0][j],t);
    }
    return ret;
  }
};
