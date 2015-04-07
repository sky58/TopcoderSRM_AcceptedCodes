//SRM602DIV1-1000 BlackBoxDiv1
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
lint mo=1000000007;
lint zyo[41000];
class BlackBoxDiv1{
	public:
	int count(int n,int m){
		zyo[0]=1;
		rep(i,40500) zyo[i+1]=(zyo[i]*2)%mo;
		lint out=zyo[m*n]-zyo[n]*m*m-zyo[m]*n*n;
		out+=(n-1)*(n-2)/2*(m-1)*(m-2)+2*m*n*(m+n)-5*n*m+3*(n+m)-3;
		out%=mo;out+=mo;
		return (int)(out%mo);
	}
};
