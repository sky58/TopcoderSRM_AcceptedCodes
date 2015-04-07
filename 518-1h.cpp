//SRM518DIV1-1000
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
lint mod=1000000007,inv2=500000004;
const int ma=1<<16;
lint a[ma+10];
lint zyo(lint x,lint y){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mod;
    	a=(a*a)%mod;y/=2;
    }
    return ret;
}
void tr(int x,int y){
	if(y<x+2) return;
	int s=(y-x)/2,z=x+s,i;
	tr(x,z);tr(z,y);
	REP(i,x,z){
		lint b=a[i];
		a[i]=(a[i]-a[i+s]+mod)%mod;
		a[i+s]=(b+a[i+s])%mod;
	}
	return;
}
void utr(int x,int y){
	if(y<x+2) return;
	int s=(y-x)/2,z=x+s,i;
	REP(i,x,z){
		lint b=a[i];
		a[i]=((a[i]+a[i+s])*inv2)%mod;
		a[i+s]=((a[i+s]-b+mod)*inv2)%mod;
	}
	utr(x,z);utr(z,y);
	return;
}
class Nim{
	public:
	int Nim::count(int k,int l){
		int i,j;
		//inv2=zyo(2,mod-2);cout<<inv2<<endl;
		rep(i,ma) a[i]=1;REP(i,l+1,ma) a[i]=0;
		a[0]=a[1]=0;
		REP(i,2,l+1){
			if(a[i]<1) continue;
			for(j=i+i;j<=l;j+=i) a[j]=0;
		}
//		rep(i,8) cout<<a[i]<<endl;
		tr(0,ma);
		rep(i,ma) a[i]=zyo(a[i],k)%mod;
		utr(0,ma);
		return (int)(a[0]%mod);
	}
};
