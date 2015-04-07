//SRM533DIV1-1000 Pikachu
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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<lint,lint> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
map<vector <int>,pint> dp[35];
vector <int> a;int n;lint con[100][100];
lint mo=1000000009;

pint rec(int x,vector <int> y){
	int m=y.size(),o,i,j,low,hi;pint ret=mp(mo,0);
	if(x>=n) return mp(0,1);
	if(y.size()<1) return mp(mo,0);
	if(dp[x][y].fi) return dp[x][y];
	rep(o,m){if(y[o]>y[0]) break;}
//	cout<<x<<' ';rep(i,m) cout<<y[i]<<' ';
	
	rep(i,o+1){
		vector <int> next;
		REP(j,o,m) next.pb(y[j]);
		rep(j,o-i){next.pb(y[0]+2);next.pb(y[0]+2);next.pb(y[0]+3);}
		if(next.size()>n-x-i) continue;sort(All(next));
		pint p=rec(x+i,next);rep(j,i) p.fi+=y[0]*a[x+j];
		if(p.fi>ret.fi) continue;
		
		lint t=1;
		if(i>0){
			REP(low,x,n){if(a[low]==a[x+i-1]) break;}
			REP(hi,x,n){if(a[hi]<a[x+i-1]) break;}
			t=(con[o][i]*con[hi-low][i+x-low])%mo;
			rep(j,i) t=(t*(j+1))%mo;
		}
		
		if(p.fi<ret.fi){ret=p;ret.se*=t;ret.se%=mo;}
		else ret.se=(ret.se+p.se*t)%mo;
	}
//	cout<<x<<' ';rep(i,m) cout<<y[i]<<' ';cout<<o<<endl;
//	cout<<ret.fi<<' '<<ret.se<<endl;
	return dp[x][y]=ret;
}
		
class Pikachu{
	public:
	vector <int> Pikachu::bestEncoding(vector <int> A){
		if(A.size()%2<1) A.pb(0);
		a=A;n=a.size();sort(All(a));reverse(All(a));
		vector <int> b,out;b.pb(0);
		int i,j;
		rep(i,55){
			con[i][i]=con[i][0]=1;REP(j,1,i) con[i][j]=(con[i-1][j]+con[i-1][j-1])%mo;
		}
		pint ret=rec(0,b);
		out.pb((int)ret.fi);out.pb((int)(ret.se%mo));return out;
	}
};
