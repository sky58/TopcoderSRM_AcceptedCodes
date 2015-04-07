//SRM526.5DIV1-1000 MagicMatchesGame
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
typedef pair<double,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int rank(vector <int> c,int b){
	vector <int> a=c;a.pb(b);int n=a.size(),i,j,ret=0;
	rep(i,25){
		int t=-1;
		REP(j,ret,n){
			if((a[j]&(1<<i))>0) t=j;
		}
		if(t>=0){
			swap(a[ret],a[t]);ret++;
			REP(j,ret,n){
				if((a[j]&(1<<i))>0) a[j]^=a[ret-1];
			}
		}
	}
	return ret;
}
class MagicMatchesGame{
	public:
	long long MagicMatchesGame::minimumArea(vector <int> a,vector <int> b,vector <int> c){
		lint out=1000000000000000000LL;int i,j,n=a.size(),k,ma=0;
		vector <double> rat,gap;vector <pint> v;vector <int> u;
		rep(i,n) rep(j,n){
			if(b[i]>b[j] && c[i]<c[j]) rat.pb((0.0+b[i]-b[j])/(c[j]-c[i]));
		}
		rat.pb(0.0),rat.pb(1e5);sort(All(rat));
		rep(i,rat.size()-1) gap.pb((rat[i]+rat[i+1])*0.5);
		rep(i,gap.size()){
//			cout<<gap[i]<<endl;
			v.clear();rep(j,n) v.pb(mp(gap[i]*c[j]+b[j],j));sort(All(v));
			u.clear();lint sumb=0,sumc=0;
			rep(j,n){
				int ind=v[j].se;
//				rep(k,u.size()) cout<<u[k]<<' ';cout<<a[ind]<<'a'<<ind<<endl;
				if(rank(u,a[ind])>u.size()){
					u.pb(a[ind]);sumb+=b[ind];sumc+=c[ind];
				}
			}
			out<?=sumb*sumc;//cout<<u.size()<<' '<<sumb<<' '<<sumc<<endl;
		}
		return out;
	}
};
