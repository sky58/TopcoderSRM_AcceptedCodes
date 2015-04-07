//SRM531DIV1-1000 BuildingReorganization
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
int b,c,n;lint d,inf=10000000000LL;vector <lint> a;
lint cal2(lint t,vector <lint> in){
	sort(All(in));in.pb(inf);int i;lint ret=0;
	rep(i,in.size()-1){
		if((in[i+1]-in[i])*(i+1)>=t){
			lint x=t/(i+1),y=t%(i+1);
			return ret+y*(in[i]+x)+(2*in[i]+x-1)*x*(i+1)/2;
		}
		ret+=(in[i]+in[i+1]-1)*(in[i+1]-in[i])*(i+1)/2;t-=(in[i+1]-in[i])*(i+1);
	}
	return ret;
}
lint cal(int it,lint t){
	vector <lint> t1,t2;int i;
	rep(i,n){
		if(i==b || i==c) continue;
		if(i<it) t1.pb(a[i]+d*abs(i-b));
		else if(i==it) t2.pb(a[i]+t+d*abs(i-c));
		else t2.pb(a[i]+d*abs(i-c));
	}
//	if(it==5 && t==0) cout<<cal2(a[b]-t,t1)<<' '<<cal2(a[c],t2)<<' '<<t*d*abs(b-it)<<' '<<(2*a[it]+t-1)*t/2<<endl;
	return cal2(a[b]-t,t1)+cal2(a[c],t2)+t*d*abs(b-it)+(2*a[it]+t-1)*t/2;
}
class BuildingReorganization{
	public:
	long long BuildingReorganization::theMin(vector <int> A,int B,int C,int D){
		int i;n=A.size();rep(i,n) a.pb(A[i]);b=B;c=C;d=D;
		lint out=8000000000000000000LL;
		rep(i,n){
			if(i==b || i==c) continue;
			if(i==0 || (i==1 && b<1) || (i==2 && b<1 && c<2)){
				out<?=cal(i,a[b]);continue;
			}
			lint hi=a[b],lo=0;
			while(hi>lo+2){
				int l=(hi+lo)/2,r=l+1;
				if(cal(i,l)<cal(i,r)) hi=r;else lo=l;
			}
			out<?=cal(i,lo);out<?=cal(i,lo+1);if(lo+2<=a[b]) out<?=cal(i,lo+2);
		}
		return out+a[b]*(a[b]-1)/2+a[c]*(a[c]-1)/2;
	}
};
