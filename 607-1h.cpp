//SRM607DIV1-1000 PulleyTautLine
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
lint inf=1145141919810893364;
lint dp[114][114][51][4];
lint co[114514][114];
double e,A,B,R,pi=3.1415926535897932384626;
lint con(lint a,int b){
	if(b==0) return 1;
	if(a>=inf) return inf;
	if(b==1) return a;
	if(b==2){
		if(0.5*a*(a-1)<1.0*inf) return a*(a-1)/2;return inf;
	}
	if(b==3){
		if(1.0/6*a*(a-1)*(a-2)<1.0*inf) return a*(a-1)/2*(a-2)/3;return inf;
	}
	if(a<114514) return co[(int)a][b];
	return inf;
}
lint cal(double a,int n){
	lint ret=0;
	rep(i,72) rep(j,72) if(dp[i][j][n-1][0]!=0){
		rep(k,i+1){
			double len=k*A+(i-k)*B+j*R;
			if(len>a) continue;
			lint rest=(lint)(0.5*(a-len)/R),b1=con(i,k),b2=con(rest+i+1,i+1);
			//if(a<110) cout<<i<<' '<<k<<' '<<rest<<' '<<b1<<' '<<b2<<endl;
			if(b2>inf/dp[i][j][n-1][0]/b1) ret=inf;
			else ret+=dp[i][j][n-1][0]*b1*b2;
			ret=min(ret,inf);
		}
	}
	//cout<<a<<' '<<ret<<endl;
	return ret;
}
class PulleyTautLine{
	public:
	double getLength(int d,int r,int n,long long K){
		e=sqrt(1.0*d*d-1.0*r*r)+r*(pi/2-acos(1.0*r/d));//cout<<1.0*r/d<<endl;
		A=d;
		B=sqrt(1.0*d*d-4.0*r*r)+2*r*(pi/2-acos(2.0*r/d));
		R=r*pi;
		//cout<<e<<' '<<A<<' '<<B<<' '<<R<<endl;
		
		memset(co,0,sizeof(co));
		rep(i,114514){
			co[i][0]=1;
			REP(j,1,min(i+1,80)) co[i][j]=min(co[i-1][j]+co[i-1][j-1],inf);
		}
		memset(dp,0,sizeof(dp));dp[0][0][0][0]=2;
		rep(i,100) rep(j,100) rep(k,n) rep(l,2){
			dp[i][j][k][l]=min(dp[i][j][k][l],inf);
			if(l<1) dp[i][j+1][k][1]+=dp[i][j][k][l];
			if(j%2==0 && k<n-1) dp[i+1][j][k+1][0]+=dp[i][j][k][l];
			if(j%2==1 && k>0) dp[i+1][j][k-1][0]+=dp[i][j][k][l];
		}
		//cout<<dp[1][0][1][0]<<endl;
		double lo=0,hi=2*inf*R;
		rep(i,100){
			double mi=(lo+hi)/2;
			if(cal(mi,n)<K) lo=mi;else hi=mi;
		}
		return lo+e*2;
	}
};
