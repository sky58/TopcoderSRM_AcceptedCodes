//SRM570DIV1-900 CurvyonRails
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
typedef int typ;
struct edge{int to;int cap;typ cost;int rev;};
const typ inf=1000000000;
const int maxv=1500;
int v;
vector <edge> gr[maxv];
int prevv[maxv],preve[maxv];typ h[maxv],dist[maxv];
void aedge(int from,int to,int cap,typ cost){
	gr[from].pb((edge){to,cap,cost,gr[to].size()});
	gr[to].pb((edge){from,0,-cost,gr[from].size()-1});
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
class CurvyonRails{
	public:
	int CurvyonRails::getmin(vector <string> a){
		int n=a.size(),m=a[0].size(),i,j,s=n*m*2,t=s+1,f=0;
		v=t+1;
		rep(i,n) rep(j,m){
			if(a[i][j]=='w') continue;
			if((i+j)%2<1){
				f+=2;
				aedge(s,i*m+j,1,0);aedge(s,i*m+j+n*m,1,0);
				if(i>0) aedge(i*m+j,i*m+j-m,1,0);
				if(i<n-1) aedge(i*m+j,i*m+j+m,1,0);
				if(j>0) aedge(i*m+j+n*m,i*m+j+n*m-1,1,0);
				if(j<m-1) aedge(i*m+j+n*m,i*m+j+n*m+1,1,0);
			}
			else{
				aedge(i*m+j,t,1,0);aedge(i*m+j+n*m,t,1,0);
			}
			int c=0;if(a[i][j]=='C') c=1;
			aedge(i*m+j,i*m+j+n*m,1,c);aedge(i*m+j+n*m,i*m+j,1,c);
		}
		return mcmf(s,t,f);
	}
};
