//SRM652DIV1-500 MaliciousPath
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
typedef pair<lint,int> pl;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<pint> gr[1010],rgr[1010];
lint dp[1010][1010],ma[1010][1010];
bool sumi[1010];
lint inf=1145141919810364364LL;
priority_queue<pl> q;
void aedge(int id,int pos,lint di){
	if(dp[id][pos]<=di) return;
	dp[id][pos]=di;q.push(mp(-di,pos));
}
class MaliciousPath{
	public:
	long long minPath(int n,int m,vector<int> from,vector<int> to,vector<int> cost){
		rep(i,from.size()){
			gr[from[i]].pb(mp(to[i],cost[i]));
			rgr[to[i]].pb(mp(from[i],cost[i]));
		}
		rep(i,n) rep(j,m+5) dp[j][i]=inf;dp[0][n-1]=0;
		memset(ma,0,sizeof(ma));
		rep(i,n+10) rep(j,to.size()){
			dp[0][from[j]]=min(dp[0][from[j]],dp[0][to[j]]+cost[j]);
		}
		if(dp[0][0]>=inf) return -1;
		rep(i,m){
			memset(sumi,false,sizeof(sumi));
			rep(j,n-1) rep(k,gr[j].size()) ma[i+1][j]=max(ma[i+1][j],dp[i][gr[j][k].fi]+gr[j][k].se);
			aedge(i+1,n-1,0);
			//if(i==0) cout<<q.size()<<endl;
			while(!q.empty()){
				pl p=q.top();q.pop();
				int pos=p.se;lint di=-p.fi;
				//if(i==0) cout<<pos<<' '<<di<<endl;
				if(sumi[pos]) continue;sumi[pos]=true;
				rep(j,rgr[pos].size()){
					int v=rgr[pos][j].fi,c=rgr[pos][j].se;
					aedge(i+1,v,max(ma[i+1][v],di+c));
				}
			}
		}
		if(dp[m][0]>=inf) return -1;
		return dp[m][0];
	}
};
