//SRM612DIV1-450 SpecialCells
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
typedef int typ;
struct edge{int to;int cap;typ cost;int rev;};
const typ inf=1000000000;
const int maxv=1100;
int v;
vector <edge> gr[maxv];
int prevv[maxv],preve[maxv];typ h[maxv],dist[maxv];
void aedge(int from,int to,int cap,typ cost){
	gr[from].pb((edge){to,cap,cost,(int)gr[to].size()});
	gr[to].pb((edge){from,0,-cost,(int)gr[from].size()-1});
	return;
}
typ mcmf(int s,int t,int f){
	typ ret=0;int i;
	for(i=0;i<v;i++) h[i]=0;
	while(f>0){
//		cout<<f<<endl;
		priority_queue<pint> q;
		for(i=0;i<v;i++) dist[i]=inf;dist[s]=0;
		q.push(mp(0,s));
		while(!q.empty()){
			pint p=q.top();q.pop();int x=p.se;typ y=p.fi;
			if(dist[x]<y) continue;
			for(i=0;i<gr[x].size();i++){
				edge &e=gr[x][i];
				if(e.cap>0 && dist[e.to]>dist[x]+e.cost+h[x]-h[e.to]){
					dist[e.to]=dist[x]+e.cost+h[x]-h[e.to];
					prevv[e.to]=x;preve[e.to]=i;
					q.push(mp(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]>=inf) return -1;
		for(i=0;i<v;i++) h[i]+=dist[i];
		int d=f;
		for(i=t;i!=s;i=prevv[i]) d=min(d,gr[prevv[i]][preve[i]].cap);
		f-=d;ret+=d*h[t];
		for(i=t;i!=s;i=prevv[i]){
			edge &e=gr[prevv[i]][preve[i]];e.cap-=d;gr[i][e.rev].cap+=d;
		}
	}
	return ret;
}
class SpecialCells{
	public:
	int guess(vector<int> x,vector<int> y){
		int n=x.size();vector<int> a=x,b=y;
		bool ng[55][55];
		sort(All(a));a.erase(unique(All(a)),a.end());
		sort(All(b));b.erase(unique(All(b)),b.end());
		int m=a.size(),o=b.size(),s=m+o,t=s+1;v=t+1;
		rep(i,n){
			x[i]=lower_bound(All(a),x[i])-a.begin();
			y[i]=lower_bound(All(b),y[i])-b.begin();
		}
		memset(ng,false,sizeof(ng));
		rep(i,n) ng[x[i]][y[i]]=true;
		rep(i,n){
			aedge(s,x[i],1,0);aedge(y[i]+m,t,1,0);
		}
		rep(i,m) rep(j,o){
			if(ng[i][j]) aedge(i,j+m,1,1);else aedge(i,j+m,1,0);
		}
		return mcmf(s,t,n);
	}
};
