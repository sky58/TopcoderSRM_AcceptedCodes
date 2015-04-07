//SRM491DIV1-900 FoxCardGame(Failed)
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
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef double typ;
typedef pair<typ,int> pint;
struct edge{int to;int cap;typ cost;int rev;};
const typ inf=1000000000,co=1e5;
const int maxv=110;
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
class FoxCardGame{
	public:
	double FoxCardGame::theMaxProportion(vector <double> a,vector <double> b,int c){
		double x=0,y=1e4;int i,j,k,n=a.size(),s=n*2,t=n*2+1;v=105;
		for(i=0;i<50;i++){
			double z=(x+y)/2;
			for(j=0;j<maxv;j++) gr[j].clear();
			for(j=0;j<n;j++){aedge(s,j,1,0);aedge(n+j,t,1,0);}
			for(j=0;j<n;j++) for(k=0;k<n;k++){
				double l=max(a[j]*b[k],a[j]+b[k]),m=min(a[j]*b[k],a[j]+b[k]);
				aedge(j,n+k,1,co-l+m*z);
//				if(fabs(z-1.25)<1e-8){cout<<j<<' '<<k<<' '<<co+l-m*z<<endl;}
			}
//			if(fabs(z-1.25)<1e-8){cout<<mcmf(s,t,c)<<endl;}
			if(mcmf(s,t,c)>co*c) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
