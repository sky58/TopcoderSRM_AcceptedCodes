//SRM609DIV1-1000 LotteryTree
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
namespace BM{
	#define MAXN0 114
	#define MAXN1 114
	#define MAXM 114514
	int n0,n1,m,ptr[MAXN0],next[MAXM],zu[MAXM];
	int to[MAXN0],fr[MAXN1],us[MAXN1],ze;
	void init(int _n0,int _n1){
		n0=_n0;n1=_n1;m=0;memset(ptr,~0,n0*4);
	}
	void ae(int u,int v){
		next[m]=ptr[u];ptr[u]=m;zu[m]=v;++m;
	}
	int augment(int u){
		int i,v;
		for(i=ptr[u];~i;i=next[i]) if(us[v=zu[i]]!=ze){
			us[v]=ze;
			if(!~fr[v] || augment(fr[v])){to[u]=v;fr[v]=u;return 1;}
		}
		return 0;
	}
	int solve(){
		memset(to,~0,n0*4);memset(fr,~0,n1*4);memset(us,~0,n1*4);
		int ret=0;
		for(ze=0;ze<n0;++ze) ret+=augment(ze);
		return ret;
	}
}
vector<int> gr[114];
int bai[114];
int dp[114][114];
int b;
int cal(int x,int y){
	if(y==0 && bai[x]>=b) return 1;
	if(y>=b) return 1;
	if(dp[x][y]>=0) return dp[x][y];
	int n=gr[x].size();if(n<1) return dp[x][y]=0;
	vector<pint> p;
	rep(i,n) rep(j,n){
		int np=gr[x][i],ne=(y*n-j*b)%bai[np];if(ne<0) ne+=bai[np];
		if(cal(np,ne)>0) p.pb(mp(i,j));
	}
	BM::init(n,n);rep(i,p.size()) BM::ae(p[i].fi,p[i].se);
	if(BM::solve()>=n) return dp[x][y]=1;return dp[x][y]=0;
}
class LotteryTree{
	public:
	string isFairTree(vector<int> a,int B){
		b=B;
		rep(i,a.size()) gr[a[i]].pb(i+1);bai[0]=1;
		rep(i,a.size()){
			int n=gr[i].size();
			rep(j,n) bai[gr[i][j]]=bai[i]*n;
		}
		memset(dp,-1,sizeof(dp));
		if(cal(0,0)>0) return "YES";return "NO";
	}
};
