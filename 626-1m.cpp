//SRM626DIV1-600 NegativeGraphDiv1
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
int n;
lint inf=1145141919810364364LL;
vector<vector<lint> > neg,pos,tmp,one;
map<int,vector<vector<lint> > > me;
vector<vector<lint> > cal(int a){
	//cout<<a<<endl;
	if(me[a].size()>0) return me[a];
	vector<vector<lint> > ret=tmp,mae=cal(a/2),ato=cal(a-a/2);
	rep(i,n) rep(j,n) rep(k,n) ret[i][j]=min(ret[i][j],mae[i][k]+ato[k][j]);
	return me[a]=ret;
}
class NegativeGraphDiv1{
	public:
	long long findMin(int N,vector<int> a,vector<int> b,vector<int> c,int d){
		n=N;int m=a.size();
		vector<lint> cl(n,inf);
		rep(i,n) tmp.pb(cl);rep(i,n) tmp[i][i]=0;neg=pos=tmp;
		rep(i,m){
			a[i]--;b[i]--;
			neg[a[i]][b[i]]=min(neg[a[i]][b[i]],(lint)-c[i]);
			pos[a[i]][b[i]]=min(pos[a[i]][b[i]],(lint)c[i]);
		}
		rep(k,n) rep(i,n) rep(j,n) pos[i][j]=min(pos[i][j],pos[i][k]+pos[k][j]);
		one=tmp;
		rep(i,n) rep(j,n) rep(k,n) one[i][j]=min(one[i][j],neg[i][k]+pos[k][j]);
		me[1]=one;me[0]=tmp;
		//cout<<one[0][0]<<endl;
		vector<vector<lint> > ret=cal(d),out=tmp;
		//cout<<ret[0][0]<<endl;
		rep(i,n) rep(j,n) rep(k,n) out[i][j]=min(out[i][j],pos[i][k]+ret[k][j]);
		return out[0][n-1];
	}
};
