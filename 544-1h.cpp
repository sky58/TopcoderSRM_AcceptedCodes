//SRM544DIV1-900 SplittingFoxes
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
typedef complex<double> pt;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <vector <lint> > tmp,one;vector <lint> cl;lint mo=1000000007;

vector <vector <lint> > mul(vector <vector <lint> > x,vector <vector <lint> > y){
	vector <vector <lint> > ret=tmp;int i,j,k,n=x.size();
	rep(i,n) rep(j,n) rep(k,n) ret[i][j]=(ret[i][j]+x[i][k]*y[k][j])%mo;
	return ret;
}
vector <vector <lint> > zyo(lint n,vector <vector <lint> > x){
    //lint ret=1,a=x;
    vector <vector <lint> > a=x,ret=tmp;
    int i;rep(i,4) ret[i][i]=1;
    while(n>0){
    	if(n%2==1) ret=mul(ret,a);
    	a=mul(a,a);n/=2;
    }
    return ret;
}
/*
map<lint,vector <vector <lint> > > ma;
vector <vector <lint> > zyo(lint n){
	if(ma[n].size()) return ma[n];
	vector <vector <lint> > ret=tmp,mae=zyo(n/2),ato=zyo(n-n/2);
	int i,j,k;
	rep(i,4) rep(j,4) rep(k,4) ret[i][j]=(ret[i][j]+mae[i][k]*ato[k][j])%mo;
	return ma[n]=ret;
}
*/
class SplittingFoxes{
	public:
	int SplittingFoxes::sum(long long n,int s,int l,int r){
		int i,j;
		rep(i,4) cl.pb(0);rep(i,4) tmp.pb(cl);one=tmp;
		one[0][0]=(lint)s+l+r;
		one[0][1]=s;
		one[1][1]=s;
		one[1][2]=l-r;
		one[2][1]=r-l;
		one[2][2]=s;
		one[2][3]=s;
		one[3][3]=s-l-r;
		rep(i,4) rep(j,4) one[i][j]=(one[i][j]%mo+mo)%mo;
		vector <vector <lint> > ret=zyo(n,one);
		//ma[1]=one;vector <vector <lint> > ret=zyo(n);
		return (int)(ret[0][3]%mo);
	}
};
