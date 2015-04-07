//SRM604DIV1-550 FoxConnection
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
vector<int> ed[55];
bool gr[55][55];bool sumi[55];
int fox[55];
int dp[55][55][55];string c;int n,inf=1000000000;
int dfs(int a){
	if(c[a]=='Y') fox[a]++;
	rep(i,ed[a].size()) fox[a]+=dfs(ed[a][i]);
	return fox[a];
}
int dfs2(int a,int b,int c){
	if(dp[a][b][c]>=0) return dp[a][b][c];
	int ret=inf;
	if(b>=ed[a].size()){
		if(c<=1) ret=0;
	}
	else{
		int t=ed[a][b];
		rep(i,max(1,c)){
			ret=min(ret,dfs2(t,0,i)+dfs2(a,b+1,c-i)+abs(i-fox[t]));
		}
	}
	return dp[a][b][c]=ret;
}
int dfs3(int a){
	int ret=dfs2(a,0,fox[0]),innode=fox[0]-fox[a]+(c[a]=='Y');
	rep(i,ed[a].size()){
		int t=ed[a][i],sum=innode;
		rep(j,ed[a].size()){
			int s=ed[a][j];if(s==t) continue;
			sum+=dfs2(s,0,0)+2*fox[s];
		}
		ret=min(ret,dfs3(t)+sum);
	}
	return ret;
}
class FoxConnection{
	public:
	int minimalDistance(vector<int> a,vector<int> b,string C){
		c=C;n=c.size();
		rep(i,n-1){
			gr[a[i]-1][b[i]-1]=true;
			gr[b[i]-1][a[i]-1]=true;
		}
		vector<int> now,next,cl;
		now.pb(0);sumi[0]=true;
		while(now.size()>0){
			rep(i,now.size()){
				int t=now[i];
				rep(j,n){
					if(gr[t][j] && !sumi[j]){next.pb(j);ed[t].pb(j);sumi[j]=true;}
				}
			}
			now=next;next=cl;
		}
		dfs(0);
		memset(dp,-1,sizeof(dp));
		return dfs3(0);
	}
};
