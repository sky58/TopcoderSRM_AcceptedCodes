//SRM523DIV1-250 CountingSeries
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
class CountingSeries{
	public:
	long long CountingSeries::countThem(long long a,long long b,long long c,long long d,long long ub){
		lint out=0;
		if(ub>=a) out=(ub-a)/b+1;
		while(c<=ub){
			if(c<a || (c-a)%b!=0) out++;
			if(d<2) break;c*=d;
		}
		return out;
	}
};
