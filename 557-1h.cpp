//SRM557DIV1-1000 XorSum
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint bit[55];
class XorAndSum{
	public:
	long long XorAndSum::maxSum(vector <long long> a){
		int n=a.size(),q=0,i,j,k;lint out=0;
		for(j=60;j>=0;j--){
			//rep(i,n) cout<<a[i]<<' ';cout<<endl;
			REP(i,q,n){
				if((a[i]&(1LL<<j))){
					swap(a[i],a[q]);bit[q]=(1LL<<j);q++;
					REP(k,q,n){
						if((a[k]&bit[q-1])) a[k]^=a[q-1];
					}
				}
			}
		}
		//rep(i,q) cout<<bit[q]<<' ';cout<<endl;
		for(i=q-1;i>0;i--){
			for(j=i-1;j>=0;j--){
				if((a[j]&bit[i])) a[j]^=a[i];
			}
		}
		REP(i,1,q) a[0]^=a[i];REP(i,1,n) a[i]^=a[0];
		rep(i,n) out+=a[i];
		return out;
	}
};
