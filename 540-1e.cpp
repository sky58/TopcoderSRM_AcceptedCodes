//SRM540DIV1-250 ImportantSequence
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
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class ImportantSequence{
	public:
	int ImportantSequence::getCount(vector <int> a,string b){
		int n=a.size(),i;lint inf=1000000000000000LL,ma=inf*100,mi=1;
		vector <lint> x,y;x.pb(1);y.pb(1);
		rep(i,n){
			if(b[i]=='+'){
				x.pb(a[i]-x[i]);y.pb(-y[i]);
			}
			else{
				x.pb(x[i]-a[i]);y.pb(y[i]);
			}
		}
		REP(i,1,n+1){
			if(y[i]<0) ma<?=x[i];
			else mi>?=2-x[i];
		}
		if(ma<mi) return 0;
		if(ma-mi>inf) return -1;return (int)(ma-mi+1);
	}
};
