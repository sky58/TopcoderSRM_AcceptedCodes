//SRM643DIV1-250 TheKingsFactorization
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
class TheKingsFactorization{
	public:
	vector<long long> getVector(long long a,vector<long long> b){
		int n=b.size();
		rep(i,n) a/=b[i];
		REP(i,2,1141919){
			while(a%i==0){a/=i;b.pb(i);}
		}
		if(a>1) b.pb(a);
		sort(All(b));
		return b;
	}
};
