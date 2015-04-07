//SRM590DIV1-500 XorCards
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
int n;int top[55];
lint cal(vector <lint> a,int ke,vector <int> pre){
	//cout<<ke<<endl;
	int rank=0;vector <lint> b=a;lint c=(1LL<<ke)-1,d=0;
	rep(i,pre.size()) c+=(1LL<<pre[i]);
	for(int i=50;i>=ke;i--){
		int f=0;
		REP(j,rank,n){
			if((b[j]&(1LL<<i))){
				lint d=b[j];b[j]=b[rank];b[rank]=d;f=1;top[rank]=i;break;
			}
		}
		if(f>0){
			rep(j,n){
				if(j!=rank && (b[j]&(1LL<<i))) b[j]^=b[rank];
			}
			rank++;
		}
	}
	rep(i,rank){
		if((c&(1LL<<top[i]))) d^=b[i];
	}
	if((c>>ke)!=(d>>ke)) return 0;
	return (1LL<<(n-rank));
}
class XorCards{
	public:
	long long numberOfWays(vector <long long> a,long long b){
		lint out=0;n=a.size();vector <int> c;
		for(int i=50;i>=0;i--){
			if((b&(1LL<<i))){out+=cal(a,i,c);c.pb(i);}
		}
		out+=cal(a,0,c);
		/*rep(i,50){
			if((a[0]&(1LL<<i))) cout<<i<<endl;
		}
		rep(i,50){
			if((a[3]&(1LL<<i))) cout<<i<<endl;
		}*/
		return out;
	}
};
