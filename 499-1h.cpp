//SRM499DIV1-1000 ImpossibleGame
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
struct edge{int a,b,c,d;};
vector <edge> g[32][32][32][32],rg[32][32][32][32];
lint ka[32][32][32][32];
int cmp[32][32][32][32];
bool sumi[32][32][32][32];
lint dp[5500],cm[5500];vector <int> g2[5500];
int ak[55][5],bk[55][5];
vector <edge> vs;
void dfs(edge e){
	sumi[e.a][e.b][e.c][e.d]=true;vector <edge> f=g[e.a][e.b][e.c][e.d];
	for(int i=0;i<f.size();i++){
		if(!sumi[f[i].a][f[i].b][f[i].c][f[i].d]) dfs(f[i]);
	}
	vs.pb(e);return;
}
void rdfs(edge e,int k){
	sumi[e.a][e.b][e.c][e.d]=true;vector <edge> f=rg[e.a][e.b][e.c][e.d];
	cmp[e.a][e.b][e.c][e.d]=k;cm[k]+=ka[e.a][e.b][e.c][e.d];
	for(int i=0;i<f.size();i++){
		if(!sumi[f[i].a][f[i].b][f[i].c][f[i].d]) rdfs(f[i],k);
	}
	return;
}
lint rec(int a){
	if(dp[a]>=0) return dp[a];lint ret=0;
	for(int i=0;i<g2[a].size();i++) ret>?=rec(g2[a][i]);
	return dp[a]=ret+cm[a];
}
class ImpossibleGame{
	public:
	long long ImpossibleGame::getMinimum(int n,vector <string> a,vector <string> b){
		int i,j,k,l,m=a.size();lint out=0;
		memset(ak,0,sizeof(ak));memset(bk,0,sizeof(bk));memset(sumi,false,sizeof(sumi));
		for(i=0;i<m;i++) for(j=0;j<a[i].size();j++){
			if(a[i][j]=='A') ak[i][0]++;if(a[i][j]=='B') ak[i][1]++;if(a[i][j]=='C') ak[i][2]++;if(a[i][j]=='D') ak[i][3]++;
			if(b[i][j]=='A') bk[i][0]++;if(b[i][j]=='B') bk[i][1]++;if(b[i][j]=='C') bk[i][2]++;if(b[i][j]=='D') bk[i][3]++;
		}
		for(i=0;i<32;i++) for(j=0;j<32;j++) for(k=0;k<32;k++) for(l=0;l<32;l++) ka[i][j][k][l]=0;ka[0][0][0][0]=1;
		for(i=0;i<n;i++) for(j=0;i+j<n;j++) for(k=0;i+j+k<n;k++) for(l=0;i+j+k+l<n;l++){
			ka[i+1][j][k][l]+=ka[i][j][k][l];
			ka[i][j+1][k][l]+=ka[i][j][k][l];
			ka[i][j][k+1][l]+=ka[i][j][k][l];
			ka[i][j][k][l+1]+=ka[i][j][k][l];
		}
		for(i=0;i<=n;i++) for(j=0;j+i<=n;j++) for(k=0;k+i+j<=n;k++) for(l=0;l<m;l++){
			if(i>=ak[l][0] && j>=ak[l][1] && k>=ak[l][2] && n-i-j-k>=ak[l][3]){
				g[i][j][k][n-i-j-k].pb((edge){i-ak[l][0]+bk[l][0],j-ak[l][1]+bk[l][1],k-ak[l][2]+bk[l][2],n-i-j-k-ak[l][3]+bk[l][3]});
				rg[i-ak[l][0]+bk[l][0]][j-ak[l][1]+bk[l][1]][k-ak[l][2]+bk[l][2]][n-i-j-k-ak[l][3]+bk[l][3]].pb((edge){i,j,k,n-i-j-k});
			}
		}
		for(i=0;i<=n;i++) for(j=0;j+i<=n;j++) for(k=0;k+i+j<=n;k++){
			if(!sumi[i][j][k][n-i-j-k]) dfs((edge){i,j,k,n-i-j-k});
		}
		memset(sumi,false,sizeof(sumi));k=0;for(i=0;i<5500;i++) cm[i]=0;
		for(i=vs.size()-1;i>=0;i--){
			if(!sumi[vs[i].a][vs[i].b][vs[i].c][vs[i].d]) rdfs(vs[i],k++);
		}
		for(i=0;i<=n;i++) for(j=0;j+i<=n;j++) for(k=0;k+i+j<=n;k++){
			vector <edge> e=g[i][j][k][n-i-j-k];
			for(l=0;l<e.size();l++){
				if(cmp[i][j][k][n-i-j-k]!=cmp[e[l].a][e[l].b][e[l].c][e[l].d]) g2[cmp[i][j][k][n-i-j-k]].pb(cmp[e[l].a][e[l].b][e[l].c][e[l].d]);
			}
		}
		for(i=0;i<5500;i++) dp[i]=-1;for(i=0;i<5400;i++) out>?=rec(i);return out;
	}
};
