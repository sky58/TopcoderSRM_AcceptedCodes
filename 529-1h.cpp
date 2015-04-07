//SRM529DIV1-900 BigAndSmallAirports
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
#define border 205
lint ca(int nb,int ma,int b,int s){
	int t=nb*b-nb*(nb-1),ns=0;
	if(t>0) ns=(t-1)/min(nb,s)+1;
	return max(0,ma-ns+1);
}
//lint cal(lint n,int blo,int bhi,int slo,int shi){
lint cal(lint n,int b,int s){
	lint ret=0;int nb;
	if(n<1) return 1;
//	REP(b,blo,bhi+1) REP(s,slo,shi+1){
//		if(s>=b) continue;
		if(s<2) ret+=min(3,(int)n+1);else ret+=n+1;
		REP(nb,1,min((int)n+1,border)) ret+=ca(nb,(int)n-nb,b,s);
		if(n>=border) ret+=(n-border+1)*(n-border+2)/2;
//	}
	return ret;
}
class BigAndSmallAirports{
	public:
	long long BigAndSmallAirports::solve(int nlo,int nhi,int blo,int bhi,int slo,int shi){
//		return cal(nhi,blo,bhi,slo,shi)-cal(nlo-1,blo,bhi,slo,shi);
		lint out=0;int b,s;
		REP(b,blo,bhi+1) REP(s,slo,shi+1){
			if(s>=b) continue;//cout<<cal(3,2,1)<<' '<<cal(2,2,1)<<endl;
			out+=cal(nhi,b,s)-cal(nlo-1,b,s);
		}
		return out;
	}
};
