//SRM570DIV1-500 CentaurCompany
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
#define MAX 36
#define MIN -36
vector <int> gr[40];
int num[40];
double df[40][75][3],dg[40][40][75][3];
bool gra[40][40];
int dfs(int now,int pre){
	int ret=1,i;
	rep(i,40){
		if(i!=pre && gra[now][i]){gr[now].pb(i);ret+=dfs(i,now);}
	}
	return num[now]=ret;
}
class CentaurCompany{
	double g(int x,int ed,int s,int color){
		if(dg[x][ed][s][color]>=-1e-13) return dg[x][ed][s][color];
		double ret=0;int i;
		if(ed==gr[x].size()){
			if(s==0) ret=1;
		}
		else{
			int rem=0,y=gr[x][ed];
			REP(i,ed+1,gr[x].size()) rem+=num[gr[x][i]];
			int lo=max(-num[y],s-rem),hi=min(num[y],s+rem);
			REP(i,lo,hi+1) ret+=f(y,i,color)*g(x,ed+1,s-i,color);
		}
		return dg[x][ed][s][color]=ret;
	}
	
	double f(int x,int s,int color){
		if(df[x][s][color]>=-1e-13) return df[x][s][color];
		double ret=0.0;
		if(x==0){
			if(s>MIN) ret+=g(x,0,s-1,1);ret+=g(x,0,s,2);
		}
		else if(color==1){
			if(s<MAX) ret+=g(x,0,s+1,1);ret+=g(x,0,s,2);
		}
		else{
			if(s>MIN) ret+=g(x,0,s-1,1);ret+=g(x,0,s,2);
		}
		return df[x][s][color]=ret;
	}
	
	public:
	double CentaurCompany::getvalue(vector <int> a,vector <int> b){
		memset(df,-1,sizeof(df));memset(dg,-1,sizeof(dg));memset(gra,false,sizeof(gra));
		int i,n=a.size()+1,j;double out=0.0;
		rep(i,n-1){gra[a[i]-1][b[i]-1]=gra[b[i]-1][a[i]-1]=true;}
		dfs(0,-1);
		//rep(i,n){rep(j,gr[i].size()) cout<<gr[i][j]<<' ';cout<<endl;}
		REP(i,MIN,MAX+1) out+=max(0,i-2)*f(0,i,0);
		return 2.0*out/(1LL<<n);
	}
};
