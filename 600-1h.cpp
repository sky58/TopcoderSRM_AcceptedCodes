//SRM600DIV1-900 LotsOfLines
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
class LotsOfLines{
	public:
	long long countDivisions(int a,int b){
		lint cro=0;
		REP(i,1,a) rep(j,b){
			if(j<1 && i>1) continue;
			if(j>=1 && gcd(i,j)>1) continue;
			lint t=(a-i)*(b-j);
			cro+=t;
			if(j>0) cro+=t;
		}
		return cro+a*b+1;
	}
};
