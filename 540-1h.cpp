//SRM540DIV1-950 ProductQuery
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int n;vector <int> a,b,c;
lint mo=1000000007;lint dp[110][110];
int endz[110];bool nz[110],endnz[110];
int invmod[5]={0,1,3,2,4};
lint cal(int m){
//	cout<<"a"<<endl;
	int i,j;lint out=0;
	vector <tint> q;rep(i,a.size()) q.pb(mp(mp(a[i],b[i]+1),c[i]%m));
top:
	rep(i,q.size()) rep(j,q.size()){
		if(i==j) continue;
		if(q[i].fi.se==q[j].fi.se && q[i].fi.fi<=q[j].fi.fi){
			if(q[j].se==0){
				if(q[i].se>0) return 0;q.erase(q.begin()+i);goto top;
			}
			else if(q[i].fi.fi==q[j].fi.fi){
				if(q[i].se!=q[j].se) return 0;q.erase(q.begin()+i);goto top;
			}
			else{
				q[i].fi.se=q[j].fi.fi;q[i].se=(q[i].se*invmod[q[j].se])%m;goto top;
			}
		}
	}
	rep(i,110) endz[i]=-1;memset(nz,false,sizeof(nz));memset(endnz,false,sizeof(endnz));
	rep(i,q.size()){
//		cout<<q[i].fi.fi<<' '<<q[i].fi.se<<' '<<q[i].se<<endl;
		if(q[i].se==0) endz[q[i].fi.se]=q[i].fi.fi;
		else{
			REP(j,q[i].fi.fi,q[i].fi.se) nz[j]=true;endnz[j]=true;
		}
	}
	rep(i,110) rep(j,110) dp[i][j]=0;dp[0][0]=1;
	rep(i,n) rep(j,n){
//		cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		if(dp[i][j]<1) continue;
		if(nz[i]){
			if(endz[i+1]<j){
				if(endnz[i+1]) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mo;
				else dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(m-1))%mo;
			}
		}
		else{
			if(endz[i+1]<j) dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(m-1))%mo;
			dp[i+1][i+1]=(dp[i+1][i+1]+dp[i][j])%mo;
		}
	}
	rep(i,n+1) out=(out+dp[n][i])%mo;return out;
}
class ProductQuery{
	public:
	int ProductQuery::theInput(int N,vector <int> A,vector <int> B,vector <int> C){
		n=N;a=A;b=B;c=C;
		lint x=cal(2),y=cal(5);cout<<x<<' '<<y<<endl;
		return (int)((x*y)%mo);
	}
};
