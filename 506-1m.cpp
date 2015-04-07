//SRM506DIV1-600 SlimeXGrandSlimeAuto
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
typedef pair<int,int> pint;
typedef int typ;
int fl[55][55];
struct edge{int to;int cap;typ cost;int rev;};
const typ inf=1000000000;
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
int de(char a){
	if(a<='9' && a>='0') return 1+(a-'0');
	if(a<='z' && a>='a') return 11+(a-'a');
	else if(a<='Z' && a>='A') return 37+(a-'A');
	return inf;
}
class SlimeXGrandSlimeAuto{
	public:
	int SlimeXGrandSlimeAuto::travel(vector <int> c,vector <int> d,vector <string> s,int ws,int cs){
		int cn=s.size(),l=c.size(),m=d.size(),i,j,k;v=l+m+3;
		for(i=0;i<55;i++) for(j=0;j<55;j++) fl[i][j]=inf;
		for(i=0;i<cn;i++) for(j=0;j<cn;j++) fl[i][j]=de(s[i][j]);for(i=0;i<55;i++) fl[i][i]=0;
		for(k=0;k<55;k++) for(i=0;i<55;i++) for(j=0;j<55;j++) fl[i][j]<?=fl[i][k]+fl[k][j];
		for(i=0;i<l;i++) aedge(0,m+i,1,ws*fl[0][c[i]]+cs*fl[c[i]][d[0]]);
		for(i=0;i<l;i++) for(j=1;j<m;j++) aedge(j,m+i,1,ws*fl[d[j-1]][c[i]]+cs*fl[c[i]][d[j]]);
		aedge(0,m+l,1,ws*fl[0][d[0]]);for(i=1;i<m;i++) aedge(i,m+l,1,ws*fl[d[i-1]][d[i]]);
		for(i=0;i<m;i++) aedge(v-2,i,1,0);for(i=0;i<l;i++) aedge(m+i,v-1,1,0);aedge(m+l,v-1,100,0);
		return mcmf(v-2,v-1,m);
	}
};
