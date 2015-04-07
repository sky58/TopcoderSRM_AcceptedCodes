//SRM614DIV1-1000 TorusSailing
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
typedef pair<int,double> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double dp[114][114][214];
vector<vector<double> > mat;
class TorusSailing{
	public:
	double expectedTime(int n,int m,int x,int y){
		rep(i,114) rep(j,114) rep(k,202) dp[i][j][k]=0.0;
		rep(i,n){
			if(i!=x || m-1!=y) dp[i][m-1][i]=1.0;
		}
		rep(j,m-1){
			if(n-1!=x || j!=y) dp[n-1][j][n+j]=1.0;
		}
		for(int i=n-2;i>=0;i--) for(int j=m-2;j>=0;j--){
			if(i==x && j==y) continue;
			rep(k,n+m) dp[i][j][k]=(dp[i+1][j][k]+dp[i][j+1][k])*0.5;dp[i][j][m+n-1]+=1.0;
		}
		rep(i,n){
			if(i==x && m-1==y) continue;
			rep(k,n+m) dp[i][m-1][k]=(dp[(i+1)%n][m-1][k]+dp[i][0][k])*0.5;dp[i][m-1][n+m-1]+=1.0;
		}
		rep(j,m-1){
			if(n-1==x && j==y) continue;
			rep(k,n+m) dp[n-1][j][k]=(dp[0][j][k]+dp[n-1][j+1][k])*0.5;dp[n-1][j][n+m-1]+=1.0;
		}
		vector<double> tmp(n+m,0.0);
		rep(i,n) mat.pb(vector<double>(dp[i][m-1],dp[i][m-1]+n+m));
		rep(j,m-1) mat.pb(vector<double>(dp[n-1][j],dp[n-1][j]+n+m));
		rep(i,n+m-1){
			mat[i][i]-=1.0;mat[i][n+m-1]*=-1.0;
		}
		rep(i,n+m-1){
			REP(j,i+1,n+m-1){
				if(fabs(mat[j][i])>fabs(mat[i][i])){
					vector<double> d=mat[i];mat[i]=mat[j];mat[j]=d;
				}
			}
			REP(j,i+1,n+m) mat[i][j]/=mat[i][i];mat[i][i]=1.0;
			rep(j,n+m-1){
				if(i==j) continue;
				REP(k,i+1,n+m) mat[j][k]-=mat[j][i]*mat[i][k];mat[j][i]=0.0;
			}
		}
		double out=dp[0][0][n+m-1];
		rep(i,n+m-1) out+=dp[0][0][i]*mat[i][n+m-1];
		return out;
	}
};