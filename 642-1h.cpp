//SRM642DIV1-800 WheelofFortune
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
double dp[364][364];
double p[364],p2[364][364],sum[364];
double aru[364][364],nai[364][364];
int mo(int a,int b){if(a>b) a-=b;return a;}
class WheelofFortune{
	public:
	double maxExpectedValue(int n,vector<int> a){
	double out=0.0,eps=1e-13;
  	REP(i,1,n+1){
  		rep(j,i) rep(k,i) aru[i][mo(j+n-k,n)]+=1.0/i;
  		if(i<n){REP(j,i,n) rep(k,i) nai[i][mo(j+n-k,n)]+=1.0/(n-i);}
  	}
    int m=a.size();
    dp[0][0]=1.0;
    rep(i,m) rep(j,i+1){
    	dp[i+1][j]+=dp[i][j]*(n-a[i])/n;
    	dp[i+1][j+1]+=dp[i][j]*a[i]/n;
    }
    rep(i,m+1) p[i]=dp[m][i];
    rep(i,m){
    	rep(j,302) rep(k,302) dp[j][k]=0.0;dp[0][0]=1.0;
    	rep(j,m) rep(k,j+1){
        	if(j!=i){dp[j+1][k]+=dp[j][k]*(n-a[j])/n;}
    		dp[j+1][k+1]+=dp[j][k]*a[j]/n;
    	}
    	rep(j,m+1) p2[i][j]=dp[m][j];
    }
    //cout<<nai[1][1]<<' '<<nai[1][2]<<' '<<nai[1][3]<<endl;
    rep(i,m+1){
    	if(p[i]<eps) continue;
    	rep(j,364) sum[j]=0.0;
    	rep(j,m){
        	double pr=p2[j][i]/p[i];
        	//cout<<i<<' '<<p[i]<<' '<<p2[j][i]<<endl;
        	REP(k,1,n) sum[k]+=aru[a[j]][k]*pr+nai[a[j]][k]*(1.0-pr);
        }
        double ma=0.0;
        REP(j,1,n) ma=max(ma,sum[j]);
        //cout<<ma<<' '<<p[i]<<endl;
        out+=(i+ma)*p[i];
    }
    return out;
  }
};
