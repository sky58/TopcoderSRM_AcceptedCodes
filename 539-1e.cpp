//SRM539DIV1-250 Over9000Rocks
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
class Over9000Rocks{
	public:
	int Over9000Rocks::countPossibilities(vector <int> a,vector <int> b){
		int n=a.size(),i,j,out=0,now=0;vector <pint> c;
		rep(i,(1<<n)){
			int mi=0,ma=1;
			rep(j,n){
				if(!(i&(1<<j))) continue;
				mi+=a[j];ma+=b[j];
			}
			if(ma>9001){c.pb(mp(max(9001,mi),1));c.pb(mp(ma,-1));}
		}
		sort(All(c));if(c.size()<1) return 0;
		rep(i,c.size()-1){
			now+=c[i].se;if(now>0) out+=c[i+1].fi-c[i].fi;
		}
		return out;
	}
};
