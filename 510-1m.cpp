//SRM510DIV1-500 TheLuckyGameDivOne
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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <lint> num;
class TheLuckyGameDivOne{
	public:
	int find(long long a,long long b,long long jl,long long bl){
		rep(i,11) rep(j,(1<<i)){	
			lint t=0;
			rep(k,i){
				t*=10;
				if(j&(1<<k)) t+=4;else t+=7;
			}
			if(t>=a && t<=b) num.pb(t);
		}
		num.pb(a-1);num.pb(b+1);
		sort(All(num));
		//rep(i,num.size()) cout<<num[i]<<endl;
		int n=num.size(),lo=0,hi=n;
		while(hi>lo){
			int mi=(hi+lo+1)/2,f=0;lint ma=a;
			vector<pint> p;
			rep(i,n-1){
				if(num[i]+1<=num[min(n-1,i+mi)]-bl) p.pb(mp(num[i]+1,num[min(n-1,i+mi)]-bl));
			}
			//cout<<mi<<endl;rep(i,p.size()) cout<<p[i].fi<<' '<<p[i].se<<endl;
			rep(i,p.size()){
				if(p[i].fi>=ma+jl-bl+1) f=1;ma=max(ma,p[i].se+1);
			}
			if(b-bl+1>=ma+jl-bl) f=1;
			if(f==1) lo=mi;else hi=mi-1;
		}
		return lo;
	}
};
