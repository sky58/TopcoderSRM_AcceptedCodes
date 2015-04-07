//SRM624DIV1-1000 TreeColoring
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
int cv,n;
vector<int> qt,qn,bl;
int par[114514],dc[114514],sumi[114514],ch[114514];
int root[114514][20];
lint dist[114514],dep[114514],sumd[114514];
int ran(void){
	cv=(cv*1999+17)%1000003;
	return cv;
}
int lca(int x,int y){
	if(dc[y]>dc[x]) swap(x,y);
	rep(i,18){
		if(((dc[x]-dc[y])&(1<<i))) x=root[x][i];
	}
	if(x==y) return x;
	for(int i=17;i>=0;i--){
		if(root[x][i]!=root[y][i]) x=root[x][i],y=root[y][i];
	}
	return par[x];
}
void cal(void){
	sumd[0]=0;rep(i,n) sumd[0]+=sumi[i]*dep[i],ch[i]=sumi[i];
	for(int i=n-1;i>0;i--) ch[par[i]]+=ch[i];
	REP(i,1,n) sumd[i]=sumd[par[i]]+dist[i]*(ch[0]-ch[i]-ch[i]);
	//rep(i,n) cout<<sumd[i]<<endl;cout<<endl;
}
class TreeColoring{
	public:
	long long color(int N,int q,int ss,int ts,int md){
		cv=ss;n=N;lint out=0;int border=300;
		rep(i,n-1){
			dist[i+1]=ran()%md;par[i+1]=ran();
			if(par[i+1]<ts) par[i+1]=i;else par[i+1]=par[i+1]%(i+1);
			//cout<<par[i+1]<<' '<<dist[i+1]<<endl;
		}
		rep(i,q){
			qt.pb(ran()%2);qn.pb(ran()%n);//cout<<qt[i]<<' '<<qn[i]<<endl;
		}
		dep[0]=dc[0]=par[0]=0;REP(i,1,n) dep[i]=dep[par[i]]+dist[i],dc[i]=dc[par[i]]+1;
		rep(i,n) root[i][0]=par[i];
		rep(i,18) rep(j,n) root[j][i+1]=root[root[j][i]][i];
		rep(i,q){
			//cout<<i<<endl;
			if(qt[i]==0){
				if(sumi[qn[i]]>0) continue;
				sumi[qn[i]]=1;bl.pb(qn[i]);
				if(bl.size()>border) cal(),bl.clear();
			}
			else{
				lint ret=sumd[qn[i]];
				rep(j,bl.size()){
					ret+=dep[qn[i]]+dep[bl[j]]-2*dep[lca(qn[i],bl[j])];//cout<<qn[i]<<' '<<bl[j]<<' '<<lca(qn[i],bl[j])<<endl;
				}
				//cout<<ret<<endl;
				out^=ret;
			}
		}
		return out;
	}
};
