//SRM554DIV1-250 TheBrickTowerMediumDivOne
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
vector<int> c[58];
class TheBrickTowerMediumDivOne{
	public:
	vector<int> find(vector<int> a){
		vector<int> b=a;
		sort(All(b));b.erase(unique(All(b)),b.end());
		int n=b.size();
		rep(i,a.size()) c[lower_bound(All(b),a[i])-b.begin()].pb(i);
		vector<int> out=c[0];
		REP(i,1,n){
			vector<int> ret;int j;
			for(j=0;c[i][j]<out[0] && j<c[i].size();j++) ret.pb(c[i][j]);
			rep(k,out.size()) ret.pb(out[k]);
			for(;j<c[i].size();j++) ret.pb(c[i][j]);
			out=ret;
		}
		return out;
	}
};
