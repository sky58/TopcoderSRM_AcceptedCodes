//SRM633DIV1-1000 GCDLCM
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
vector<int> a,b,c;int n,m;string s;
int lo[210],hi[210],num[210];
bool gr[410][410];
vector<int> ed[410];
void dfs(int a,int b){
	if(gr[a][b]) return;
	gr[a][b]=true;
	rep(i,ed[b].size()) dfs(a,ed[b][i]);
}
bool cal(void){
	rep(i,n) lo[i]=0,hi[i]=114514;
	rep(i,m){
		if(s[i]=='G') lo[a[i]]=max(lo[a[i]],num[i]),lo[b[i]]=max(lo[b[i]],num[i]);
		else hi[a[i]]=min(hi[a[i]],num[i]),hi[b[i]]=min(hi[b[i]],num[i]);
	}
	rep(i,n){
		//cout<<lo[i]<<' '<<hi[i]<<endl;
		if(lo[i]>hi[i]) return false;
	}
	memset(gr,false,sizeof(gr));rep(i,410) ed[i].clear();
	rep(i,m){
		if(lo[a[i]]!=num[i] && lo[b[i]]!=num[i]) ed[a[i]].pb(n+b[i]),ed[b[i]].pb(n+a[i]);//gr[a[i]][n+b[i]]=gr[b[i]][n+a[i]]=true;
		if(lo[a[i]]!=num[i] && hi[b[i]]!=num[i]) ed[a[i]].pb(b[i]),ed[n+b[i]].pb(n+a[i]);//gr[a[i]][b[i]]=gr[n+b[i]][n+a[i]]=true;
		if(hi[a[i]]!=num[i] && lo[b[i]]!=num[i]) ed[n+a[i]].pb(n+b[i]),ed[b[i]].pb(a[i]);//gr[n+a[i]][n+b[i]]=gr[b[i]][a[i]]=true;
		if(hi[a[i]]!=num[i] && hi[b[i]]!=num[i]) ed[n+a[i]].pb(b[i]),ed[n+b[i]].pb(a[i]);//gr[n+a[i]][b[i]]=gr[n+b[i]][a[i]]=true;
	}
	//rep(k,2*n) rep(i,2*n) rep(j,2*n){if(gr[i][k] && gr[k][j]) gr[i][j]=true;}
	rep(i,2*n) dfs(i,i);
	rep(i,n){
		if(gr[i][i+n] && gr[i+n][i]) return false;
	}
	return true;
}
class GCDLCM{
	public:
	string possible(int N,string S,vector<int> A,vector<int> B,vector<int> C){
		a=A;b=B;c=C;n=N;s=S;
		m=a.size();
		vector<int> so;
		rep(i,m){
			for(int j=2;j*j<=C[i];j++){
				if(C[i]%j==0) so.pb(j);
				while(C[i]%j==0) C[i]/=j;
			}
			if(C[i]>1) so.pb(C[i]);
		}
		sort(All(so));so.erase(unique(All(so)),so.end());
		rep(i,so.size()){
			vector<int> c2=c;
			rep(j,m){
				num[j]=0;
				while(c2[j]%so[i]==0) c2[j]/=so[i],num[j]++;
			}
			//rep(j,m) cout<<num[j]<<' ';cout<<endl;
			if(!cal()) return "Solution does not exist";
		}
		return "Solution exists";
	}
};
