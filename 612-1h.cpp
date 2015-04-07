//SRM612DIV1-900 LeftAndRightHandedDiv1
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint sum[1000010],pos[1000010];
int m=0;lint N;
lint cal(int a){
	int l=(m-1)/2,r=m-l-1;lint out=0;
	if(l<=a){
		out+=pos[a]*l-(lint)l*(l+1)/2-(sum[a]-sum[a-l]);
		out+=sum[m]-sum[a+1]+sum[a-l]+N*(a-l)-(pos[a]*r+(lint)r*(r+1)/2);
	}
	else{
		out+=sum[a+r+1]-sum[a+1]-(pos[a]*r+(lint)r*(r+1)/2);
		out+=pos[a]*l-(lint)l*(l+1)/2-(sum[a]+sum[m]-sum[a+r+1]-N*(l-a));
	}
	//cout<<a<<' '<<l<<' '<<r<<' '<<out<<endl;
	return out;
}
class LeftAndRightHandedDiv1{
	public:
	long long countSwaps(string y,int a,int b,int c,int d,int n){
		lint x=a,out=1234567890123456789;N=n;
		rep(i,n){
			char e=y[(int)(x%(int)y.size())];
			if(e=='R'){
				pos[m]=i;sum[m+1]=sum[m]+i;m++;
			}
			x=(x*b+c)%d;
		}
		if(m==0) return 0;
		//rep(i,m+1) cout<<sum[i]<<endl;
		rep(i,m) out=min(out,cal(i));
		return out;
	}
};
