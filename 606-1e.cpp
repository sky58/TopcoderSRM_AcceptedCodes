//SRM606DIV1-250 EllysNumberGuessing
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
vector<int> a,b;
bool ok(int x){cout<<x<<endl;
	if(x<1 || x>1000000000) return false;
	rep(i,a.size()){
		if(abs(a[i]-x)!=b[i]) return false;
	}
	return true;
}
class EllysNumberGuessing{
	public:
	int getNumber(vector<int> A,vector<int> B){
		a=A;b=B;vector<int> out;
		if(ok(a[0]-b[0])) out.pb(a[0]-b[0]);
		if(ok(a[0]+b[0])) out.pb(a[0]+b[0]);
		if(out.size()>1) return -1;if(out.size()<1) return -2;return out[0];
	}
};
