//SRM425DIV1-1000 RoadsOfKingdom
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
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double prob[20][20];
double conall[20][(1<<16)+10],conany[20][(1<<16)+10],one[20][(1<<16)+10];
int n;
double dp[(1<<16)+10];
double con(int s,int v,int x){return conall[v][x]*conany[v][s-x];}
double dis(int s1,int s2){
	double ret=1.0;int i;
	rep(i,n){
		if((s1&(1<<i))) ret*=conany[i][s2];
	}
	return ret;
}
class RoadsOfKingdom{
	public:
	double RoadsOfKingdom::getProbability(vector <string> a){
		n=a.size();int i,j,k;
		rep(i,n) rep(j,n) prob[i][j]=0.125*(a[i][j]-'0');
		rep(i,n) rep(j,(1<<n)){
			conall[i][j]=conany[i][j]=1.0;
			rep(k,n){
				if(!(j&(1<<k))) continue;
				conall[i][j]*=prob[i][k];conany[i][j]*=(1.0-prob[i][k]);
			}
		}
		rep(i,n) rep(j,(1<<n)){
			double ze=1.0,on=0.0;
			rep(k,n){
				if(!(j&(1<<k))) continue;
				on=on*(1.0-prob[i][k])+ze*prob[i][k];ze*=(1.0-prob[i][k]);
			}
			one[i][j]=on;
		}
		rep(i,(1<<n)){
			if(__builtin_popcount(i)<2){dp[i]=1.0;continue;}
			dp[i]=0.0;int v,w;
			for(v=0;v<n;v++){if((i&(1<<v))) break;}
			for(w=v+1;w<n;w++){if((i&(1<<w))) break;}
			for(j=i;j>0;j=i&(j-1)){
//				cout<<j<<endl;
				if((j&(1<<v)) || !(j&(1<<w))) continue;
				dp[i]+=dp[j]*dp[i-j]*dis(i-j-(1<<v),j)*one[v][j];
//				rep(k,n){
//					if(!(j&(1<<k))) continue;
//					dp[i]+=dp[j]*dp[i-j]*dis(i-j-(1<<v),j)*con(j,v,(1<<k));
//				}
			}
		}
		return dp[(1<<n)-1];
	}
};
