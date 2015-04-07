//SRM453.5DIV1-1000 AlmostLuckyNumbers
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
typedef pair<lint,int> pint;
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class TheAlmostLuckyNumbers{
	public:
	long long TheAlmostLuckyNumbers::count(long long a,long long b){
		int i,j,k;lint out=0,inf=100000;inf*=inf;
		vector <lint> ki;
		for(i=1;i<11;i++) for(j=0;j<(1<<i);j++){
			lint t=0;int f=0;
			for(k=i-1;k>=0;k--){
				t*=10;if(j&(1<<k)) t+=7;else t+=4;
			}
			for(k=0;k<ki.size();k++){if(t%ki[k]==0) f=1;}
			if(f==1) continue;ki.pb(t);
		}
		vector <pint> ka;reverse(ki.begin(),ki.end());
		for(i=0;i<ki.size();i++){
			lint t=ki[i];int n=ka.size();
			ka.pb(mp(t,1));
			for(k=0;k<n;k++){
				lint s=gcd(t,ka[k].fi);
				if(t/s<=(inf-1)/ka[k].fi+1) ka.pb(mp(t/s*ka[k].fi,ka[k].se*-1));
			}
		}
		for(i=0;i<ka.size();i++) out+=(b/ka[i].fi)*ka[i].se;
		for(i=0;i<ka.size();i++) out-=((a-1)/ka[i].fi)*ka[i].se;
		return out;
	}
};
