//SRM614DIV1-250 MinimumSquare
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
class MinimumSquare{
	public:
	long long minArea(vector<int> X,vector<int> Y,int K){
		lint lo=2,hi=2000000002LL;
		int n=X.size();
		vector<lint> x,y;rep(i,n) x.pb(X[i]),y.pb(Y[i]);
		while(hi>lo){
			lint mi=(hi+lo)/2;int f=0;
			rep(i,n) rep(j,n){
				int t=0;
				rep(k,n){
					if(x[k]>=x[i] && x[k]<=x[i]+mi-2 && y[k]>=y[j] && y[k]<=y[j]+mi-2) t++;
				}
				if(t>=K) f=1;
			}
			if(f>0) hi=mi;else lo=mi+1;
		}
		return lo*lo;
	}
};
