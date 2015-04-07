//SRM521DIV1-500 RangeSquaredSubsets
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
class RangeSquaredSubsets{
	public:
	long long RangeSquaredSubsets::countSubsets(int lo,int hi,vector <int> x,vector <int> y){
		int i,j,k,l,m,n=x.size(),inf=1000000000;
		set<int> nx,ny;set<lint> out;
		rep(i,n){nx.insert(x[i]);ny.insert(y[i]);}
		nx.insert(-inf);nx.insert(inf);ny.insert(-inf);ny.insert(inf);
		vector <int> mx=vector <int>(nx.begin(),nx.end()),my=vector <int>(ny.begin(),ny.end());
		REP(i,1,mx.size()-1) REP(j,1,my.size()-1) REP(k,i,mx.size()-1) REP(l,j,my.size()-1){
			int ma=min(mx[k+1]-mx[i-1],my[l+1]-my[j-1]),mi=max(mx[k]-mx[i],my[l]-my[j]);
			if(mi>hi || ma<=lo || mi>=ma) continue;
			lint t=0;
			rep(m,n){
				if(x[m]>=mx[i] && x[m]<=mx[k] && y[m]>=my[j] && y[m]<=my[l]) t+=(1LL<<m);
			}
			if(t>0) out.insert(t);
		}
		return out.size();
	}
};
