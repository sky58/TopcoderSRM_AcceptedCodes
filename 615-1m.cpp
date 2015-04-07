//SRM615DIV1-550 LongLongtripDiv1
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
typedef pair<lint,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[55][20010],d2[55][20010];
priority_queue<tint> q;
vector<pint> gr[55];
void aedge(int a,int b,lint c){
	if(dp[a][b]>c){
		dp[a][b]=c;q.push(mp(-c,mp(a,b)));
	}
}
class LongLongTripDiv1{
	public:
	string isAble(int n,vector<int> a,vector<int> b,vector<int> c,long long t){
		rep(i,a.size()){
			gr[a[i]].pb(mp(b[i],c[i]));
			gr[b[i]].pb(mp(a[i],c[i]));
		}
		lint inf=1234567890123456789LL;int m=20010;
		if(gr[0].size()<1) return "Impossible";
		rep(i,gr[0].size()) m=min(m,gr[0][i].se*2);
		rep(i,n) rep(j,m) dp[i][j]=d2[i][j]=inf;aedge(0,0,0);
		while(!q.empty()){
			tint p=q.top();q.pop();
			int a=p.se.fi,b=p.se.se;lint c=-p.fi;
			//if(dp[a][b]>=c) continue;dp[a][b]=c;
			if(dp[a][b]>c) continue;
			rep(i,gr[a].size()){
				lint d=c+gr[a][i].se;
				aedge(gr[a][i].fi,d%m,d);
			}
		}
		if(dp[n-1][(int)(t%m)]<=t) return "Possible";
		return "Impossible";
	}
};
