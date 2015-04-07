//SRM640DIV1-250 ChristmasTreeDecoration
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
bool sumi[58];
vector<int> ed[58];
void dfs(int a){
	if(sumi[a]) return;
	sumi[a]=true;
	rep(i,ed[a].size()) dfs(ed[a][i]);
}
class ChristmasTreeDecoration{
	public:
	int solve(vector<int> a,vector<int> b,vector<int> c){
		int n=a.size(),m=b.size(),out=-1;
		rep(i,m){
			b[i]--;c[i]--;
			if(a[b[i]]!=a[c[i]]) ed[b[i]].pb(c[i]),ed[c[i]].pb(b[i]);
		}
		memset(sumi,false,sizeof(sumi));
		rep(i,n){
			if(sumi[i]) continue;
			out++;dfs(i);
		}
		return out;
	}
};
