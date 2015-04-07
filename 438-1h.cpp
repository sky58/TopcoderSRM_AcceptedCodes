//SRM438DIV1-1000 FeudaliasWar
#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

//Dinic
typedef int F;
#define F_INF (1<<29)
#define MAXV 2600
#define MAXE 260000

struct MaxFlow{
	int V,E;
	F cap[MAXE],flow[MAXE];
	int to[MAXE],prev[MAXE],last[MAXV],used[MAXV],level[MAXV];
	
	MaxFlow(int n){
		V=n;E=0;
		int i;REP(i,V) last[i]=-1;
	}
	
	void add_edge(int x,int y,F f){
		cap[E]=f;flow[E]=0;to[E]=y;prev[E]=last[x];last[x]=E;E++;
		cap[E]=0;flow[E]=0;to[E]=x;prev[E]=last[y];last[y]=E;E++;
	}
	
	bool bfs(int s,int t){
		int i;
		REP(i,V) level[i]=-1;
		queue <int> q;
		q.push(s);level[s]=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(i=last[x];i>=0;i=prev[i]) if(level[to[i]]==-1 && cap[i]>flow[i]){
				q.push(to[i]);level[to[i]]=level[x]+1;
			}
		}
		return (level[t]!=-1);
	}
	
	F dfs(int v,int t,F f){
		int i;
		if(v==t) return f;
		for(i=used[v];i>=0;used[v]=i=prev[i]) if(level[to[i]]>level[v] && cap[i]>flow[i]){
			F tmp=dfs(to[i],t,min(f,cap[i]-flow[i]));
			if(tmp>0){flow[i]+=tmp;flow[i^1]-=tmp;return tmp;}
		}
		return 0;
	}
	
	F maxflow(int s,int t){
		int i;
		while(bfs(s,t)){
			REP(i,V) used[i]=last[i];
			while(dfs(s,t,F_INF)!=0);
		}
		F ans=0;
		for(i=last[s];i>=0;i=prev[i]) ans+=flow[i];
		return ans;
	}
};
class FeudaliasWar{
	public:
	double FeudaliasWar::getMinimumTime(vector <int> sx,vector <int> sy,vector <int> bx,vector <int> by,int a,int b,int c){
		int n=bx.size(),m=sx.size(),i,j,k,l;
		double x=0.0,y=10e10,f=(double)(a+b*60)/60,g=(double)a/60;
		double dist[60][60];
		
		for(i=0;i<n;i++) for(j=0;j<m;j++) dist[i][j]=sqrt((double)(bx[i]-sx[j])*(bx[i]-sx[j])+(double)(by[i]-sy[j])*(by[i]-sy[j]));
		for(i=0;i<70;i++){
			double z=(x+y)/2;MaxFlow mf(n*m+m+2);
			for(j=0;j<m*n;j++) mf.add_edge(n*m+m,j,1);
			for(j=0;j<m;j++) mf.add_edge(n*m+j,n*m+m+1,1);
			for(j=0;j<n;j++) for(k=0;k<m;k++) for(l=0;l<m;l++){
				if(dist[j][k]<(z-f*l-g)*c+10e-12){
					mf.add_edge(j*m+l,n*m+k,1);//printf("%f\n%d %d %d\n",z,j,k,l);
				}
			}
//			cout<<mf.maxflow(n*m+m,n*m+m+1);
			if(mf.maxflow(n*m+m,n*m+m+1)==m) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
