//SRM352DIV1-500 FibonacciKnapsack
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<lint,lint> pint;
map<pint,lint> memo;
vector <pint> pl,pl2;
lint rec(lint x,lint y){
	if(x<0) return 0;
	if(memo[mp(x,y)]) return memo[mp(x,y)];
	if(y>=pl2[(int)x].fi) return pl2[(int)x].se;
	lint ret=rec(x-1,y);
	if(pl[(int)x].fi<=y) ret>?=rec(x-1,y-pl[(int)x].fi)+pl[(int)x].se;
	return memo[mp(x,y)]=ret;
}
class FibonacciKnapsack{
	public:
	long long FibonacciKnapsack::maximalCost(vector <string> a,string b){
		int i,n=a.size();lint x,y,x2=0,y2=0,c;istringstream sin(b);sin>>c;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>x>>y;pl.pb(mp(x,y));
		}
		sort(pl.begin(),pl.end());
		for(i=0;i<n;i++){
			x2+=pl[i].fi;y2+=pl[i].se;pl2.pb(mp(x2,y2));
		}
		return rec(n-1,c);
	}
};
