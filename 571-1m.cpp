//SRM517DIV1-500 MagicMolecule
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
vector <int> a;vector <string> b;int n;
int rec(int num,lint mask){
	if(num*3<n*2) return -1;
	int ret=0,i,j;
	rep(i,n) REP(j,i+1,n){
		if(b[i][j]=='N' && !(mask&(1LL<<i)) && !(mask&(1LL<<j))) return max(rec(num-1,mask+(1LL<<i)),rec(num-1,mask+(1LL<<j)));
	}
	rep(i,n){
		if(!(mask&(1LL<<i))) ret+=a[i];
	}
	return ret;
}
class MagicMolecule{
	public:
	int MagicMolecule::maxMagicPower(vector <int> A,vector <string> B){
		a=A;b=B;n=a.size();
		return rec(n,0);
	}
};
