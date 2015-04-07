//SRM245DIV1-1000 SandTimers
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
#define fi first.first
#define se first.second
#define th second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
typedef pair<int,tint> edge;
int dist[22][22][22];
vector <edge> e1[22][22][22],e2[22][22][22];
bool sumi[22][22][22][370];bool ret[370];
void aedge(tint a,tint b,int c){
	e1[a.fi][a.se][a.th].pb(mp(c,b));e2[b.fi][b.se][b.th].pb(mp(c,a));return;
}
void dfs(int a,int b,int c,int d){
	if(d>365) return;if(sumi[a][b][c][d]) return;sumi[a][b][c][d]=true;
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
//	if(a+b+c<1) cout<<d<<endl;
	for(int i=0;i<e2[a][b][c].size();i++){
		edge x=e2[a][b][c][i];
		dfs(x.th.fi,x.th.se,x.th.th,d+x.first);
	}
	return;
}
int ca(int a){if(a<1) return 0;return a;}
class SandTimers{
	public:
	vector <int> SandTimers::badIntervals(vector <int> a,int b,int c){
		int i,j,k,l,inf=10000;vector <int> out;
		while(a.size()<3) a.pb(0);memset(sumi,false,sizeof(sumi));memset(ret,false,sizeof(ret));
		for(i=0;i<22;i++) for(j=0;j<22;j++) for(k=0;k<22;k++) dist[i][j][k]=inf;
		for(i=0;i<=a[0];i++) for(j=0;j<=a[1];j++) for(k=0;k<=a[2];k++){
			tint d=mp(mp(i,j),k);//aedge(d,mp(mp(ca(i),ca(j)),ca(k)),1);
//			int e=min(min(i,j),k);aedge(d,mp(mp(i-e,j-e),k-e),e);
			aedge(d,mp(mp(ca(i-i),ca(j-i)),ca(k-i)),i);
			aedge(d,mp(mp(ca(i-j),ca(j-j)),ca(k-j)),j);
			aedge(d,mp(mp(ca(i-k),ca(j-k)),ca(k-k)),k);
			aedge(d,mp(mp(a[0]-i,j),k),0);
			aedge(d,mp(mp(i,a[1]-j),k),0);
			aedge(d,mp(mp(i,j),a[2]-k),0);
		}
		priority_queue <edge> q;q.push(mp(0,mp(mp(0,0),0)));
		while(!q.empty()){
			edge p=q.top();q.pop();int x=p.th.fi,y=p.th.se,z=p.th.th,w=p.first;
			if(dist[x][y][z]<inf) continue;dist[x][y][z]=-w;
			for(i=0;i<e1[x][y][z].size();i++){
				q.push(mp(w-e1[x][y][z][i].first,e1[x][y][z][i].th));
			}
		}
		for(i=0;i<=a[0];i++) for(j=0;j<=a[1];j++) for(k=0;k<=a[2];k++) dfs(i,j,k,0);
		for(i=0;i<=a[0];i++) for(j=0;j<=a[1];j++) for(k=0;k<=a[2];k++) for(l=0;l<=b;l++){
			if(sumi[i][j][k][l] && dist[i][j][k]+l<=c) ret[l]=true;
		}
		for(i=0;i<=b;i++){if(!ret[i]) out.pb(i);}return out;
	}
};
