//SRM561DIV1-550 CirclesGame
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
int dp[55];
bool can[55][110];
bool in[55][55];
vector <int> gr[55],rgr[55];
vector <int> x,y;
void dfs(int a){
	int i,xo=0,j;vector <int> lis;
	/*cout<<a<<endl;
	if(gr[a].size()<1){
		can[a][0]=true;dp[a]=1;return;
	}*/
	rep(i,gr[a].size()){
		dfs(gr[a][i]);lis.pb(dp[gr[a][i]]);xo^=dp[gr[a][i]];//(xo|dp[gr[a][i]])-(xo&dp[gr[a][i]]);
	}
	//cout<<a<<'a'<<xo<<endl;
	memset(can[a],false,sizeof(can[a]));can[a][xo]=true;
	rep(i,gr[a].size()){
		int nx=(xo^lis[i]);
		rep(j,110){
			if(can[gr[a][i]][j] && (nx^j)<110) can[a][(nx^j)]=true;
		}
	}
	rep(i,110){
		if(!can[a][i]){dp[a]=i;break;}
	}
	//cout<<a<<' '<<dp[a]<<endl;
	return;
}
double dist(int a,int b){
	return sqrt((0.0+x[a]-x[b])*(x[a]-x[b])+(0.0+y[a]-y[b])*(y[a]-y[b]));
}
class CirclesGame{
	public:
	string CirclesGame::whoCanWin(vector <int> X,vector <int> Y,vector <int> r){
		x=X;y=Y;int i,j,n=x.size(),out=0,k;
		memset(in,false,sizeof(in));
		rep(i,n) rep(j,n){
			if(i!=j && dist(i,j)+r[j]<1.0*r[i]){
				//cout<<i<<' '<<j<<endl;
				in[i][j]=true;
			}
		}
		rep(i,n) rep(j,n){
			if(i==j || !in[i][j]) continue;
			int f=1;
			rep(k,n){
				if(i!=k && j!=k && in[k][j] && in[i][k]) f=0;
			}
			if(f>0){gr[i].pb(j);rgr[j].pb(i);}
		}
		//rep(i,55) dp[i]=-1;
		rep(i,n){
			cout<<i<<": ";rep(j,gr[i].size()) cout<<gr[i][j]<<' ';cout<<endl;
		}
		rep(i,n){
			if(rgr[i].size()>0) continue;
			dfs(i);out^=dp[i];
			cout<<i<<' '<<dp[i]<<endl;
		}
		if(out==0) return "Bob";return "Alice";
	}
};
