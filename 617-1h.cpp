//SRM617DIV1-800 FatStrings
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
int dp[27][27];
int cal(string a,string b){
	int n=a.size();
	rep(i,n+1) rep(j,n+1) dp[i][j]=1145141919;dp[0][0]=0;
	rep(i,n+1) rep(j,n+1){
		if(i<n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		if(j<n) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
		if(i<n && j<n) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(a[i]==b[j]?0:1));
	}
	return dp[n][n];
}
class FarStrings{
	public:
	vector<string> find(string a){
		int n=a.size();char w='a';
		vector<string> out;
		rep(i,114) rep(j,n){if(a[j]==w) w++;}
		string b=a;
		rep(i,n){
			if(b[i]!='a'){b[i]='a';out.pb(b);}
		}
		REP(i,out.size(),n){
			string ret(n,w);
			rep(j,n){	
				for(ret[j]='a';ret[j]<='z';ret[j]++){
					if(cal(a,ret)>i) break;
				}
			}
			out.pb(ret);
		}
		return out;
	}
};
