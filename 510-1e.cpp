//SRM510DIV1-250 TheAlmostLuckyNumbersDivOne
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
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class TheAlmostLuckyNumbersDivOne{
	public:
	long long TheAlmostLuckyNumbersDivOne::find(long long a,long long b){
		int i,j,k,l;lint out=0;
		vector <lint> zyo;zyo.pb(1);
		rep(i,18) zyo.pb(zyo[i]*10);
		rep(i,17){
			rep(j,(1<<i)){
				lint t=0;
				rep(k,i){
					t*=10;if(j&(1<<k)) t+=4;else t+=7;
				}
				if(a<=t && b>=t) out++;
//				cout<<t<<endl;
				if(i<16){
					rep(k,i+1) rep(l,10){
						if(l==4 || l==7) continue;
						if(k==i && l==0) continue;
						lint x=zyo[k]*l+t%zyo[k]+(t/zyo[k])*zyo[k+1];
						if(a<=x && b>=x) out++;
//						cout<<'a'<<x<<endl;
					}
				}
			}
		}
		return out;
	}
};
