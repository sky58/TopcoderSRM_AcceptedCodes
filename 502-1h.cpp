SRM502DIV1-1000 TheCowDivOne
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
map<vector <int>,int> dp;
int n;lint mo=1000000007;
int gcd(int a,int b){
	if(b<1) return a;return gcd(b,a%b);
}
int modPow(int x,int y,int m){
	lint ret=1,a=x;
	while(y>0){
		if(y%2>0) ret=(ret*a)%m;a=(a*a)%m;y/=2;
	}
	return (int)ret;
}
int invMod(int a,int b){
	return modPow(a,b-2,b);
}
int cal(int d,int k,int a){
	if(k<1) return 1;
	vector <int> v;v.pb(d);v.pb(k);v.pb(a);
	if(dp.find(v)!=dp.end()) return dp[v];
	lint g=gcd(d,a),p=(cal((int)g,k-1,1)*(((n*g)/d)%mo))%mo,q=((lint)cal(d,k-1,(a+1)%d)*(k-1))%mo,ret=(p+mo-q)%mo;
//	cout<<d<<' '<<k<<' '<<a<<' '<<ret<<endl;
	return dp[v]=(int)ret;
}
class TheCowDivOne{
	public:
	int TheCowDivOne::find(int N,int k){
		n=N;lint out=cal(n,k,1);//cout<<out<<endl;
		for(int i=2;i<=k;i++) out=(out*invMod(i,mo))%mo;
		return (int)out;
	}
};
