//SRM535DIV1-250 FoxAndGCDLCM
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
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class FoxAndGCDLCM{
	public:
	long long FoxAndGCDLCM::get(long long a,long long b){
		if(b%a>0) return -1;
		lint c=b/a,i,out=1000000000000000LL;
		for(i=1;i*i<=c;i++){
			if(c%i==0 && gcd(i,c/i)==1) out<?=i+c/i;
		}
		return out*a;
	}
};
