//SRM433DIV1-1000 BarbarianInvasion(failed)
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
#define MAXV 5100
#define MAXE 15000

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
class BarbarianInvasion{
	public:
	int BarbarianInvasion::minimalDetachment(vector <string> a,vector <int> b){
		int n=a.size(),m=a[0].size(),v=n*m,mo=10000000,mo2=50000000,i,j,k;
		int px[4]={0,0,1,-1};int py[4]={1,-1,0,0};
		for(i=0;i<26;i++) b[i]+=mo;
		
		MaxFlow mf(v*2+2);
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]<='Z' && a[i][j]>='A') mf.add_edge(i*m+j,v+i*m+j,b[(a[i][j]-'A')]);
			if(a[i][j]=='*'){
				mf.add_edge(i*m+j,v+i*m+j,mo2);mf.add_edge(v*2,i*m+j,mo2);
			}
			for(k=0;k<4;k++){
				int x=i+px[k],y=j+py[k];
				if(x<0 || y<0 || x>=n || y>=m) continue;
				mf.add_edge(v+i*m+j,x*m+y,mo2);
			}
			if(i==0 || j==0 || i==n-1 || j==m-1) mf.add_edge(v+i*m+j,v*2+1,mo2);
		}
		return mf.maxflow(v*2,v*2+1)%mo;
	}
};
