//SRM599DIV1-250 BigFatInteger
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
int div(int a){
	rep(i,100){
		if((1<<i)>=a) return i;
	}
}
class BigFatInteger{
	public:
	int minOperations(int a,int b){
		vector <int> c;
		for(int i=2;i<=a;i++){
			int t=0;
			while(a%i==0){a/=i;t++;}
			if(t>0) c.pb(t);
		}
		int out=0,n=c.size();
		rep(i,n) out=max(out,div(c[i]*b));
		return out+n;
	}
};
