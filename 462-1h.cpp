//SRM462DIV1-1000 WarTransportation
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
vector<pint> gr[114],rgr[114];vector<int> id[114];
int di[114][514];
bool sumi[114];
int ma[114],dp[114];
priority_queue<pint> q;
void aedge(int i,int x,int y){
	if(di[x][i]<=y) return;
	di[x][i]=y;q.push(mp(-y,x));
}
class WarTransportation{
	public:
	int messenger(int n,vector<string> in){
		int m=0,inf=1145141919,a,b,c;
		string s="";rep(i,in.size()) s+=in[i];
		rep(i,s.size()){
			if(s[i]==',') s[i]=' ';else if(s[i]==' ') s[i]=',';
		}
		istringstream sin(s);
		while(sin>>s){
			rep(i,s.size()){if(s[i]==',') s[i]=' ';}
			istringstream sin2(s);sin2>>a>>b>>c;a--;b--;gr[a].pb(mp(b,c));rgr[b].pb(mp(a,c));id[b].pb(m);m++;
		}
		rep(i,m){
			rep(j,n) di[j][i]=inf;memset(sumi,false,sizeof(sumi));aedge(i,1,0);
			while(!q.empty()){
				pint p=q.top();q.pop();
				int x=p.se,y=-p.fi;
				if(sumi[x]) continue;sumi[x]=true;
				rep(j,rgr[x].size()){
					if(i!=id[x][j]) aedge(i,rgr[x][j].fi,y+rgr[x][j].se);
				}
			}
		}
		memset(ma,0,sizeof(ma));rep(i,n) rep(j,m) ma[i]=max(ma[i],di[i][j]);
		rep(i,n) dp[i]=inf;dp[1]=0;
		rep(i,1919) rep(j,n){
			int mi=inf;
			rep(k,gr[j].size()) mi=min(mi,gr[j][k].se+dp[gr[j][k].fi]);
			dp[j]=min(dp[j],max(mi,ma[j]));
		}
		if(dp[0]>=inf) return -1;return dp[0];
	}
};
