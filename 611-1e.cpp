//SRM611DIV1-250 LCMSet
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
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class LCMSet{
	public:
	string equal(vector<int> a,vector<int> b){
		int n=a.size(),m=b.size();
		rep(i,n){
			int t=1;
			rep(j,m){
				if(a[i]%b[j]==0) t=t/gcd(t,b[j])*b[j];
			}
			if(t!=a[i]) return "Not equal";
		}
		rep(i,m){
			int t=1;
			rep(j,n){
				if(b[i]%a[j]==0) t=t/gcd(t,a[j])*a[j];
			}
			if(t!=b[i]) return "Not equal";
		}
		return "Equal";
	}
};
