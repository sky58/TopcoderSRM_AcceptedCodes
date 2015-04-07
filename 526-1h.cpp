//SRM526DIV1-1000 DengklekMessage
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
double dp[515][515];
int po[510][50],next[510][50];
vector <int> build(string a){
	int n=a.size(),t=-1,i;
	vector <int> ret;rep(i,n+5) ret.pb(-1);
	rep(i,n){
		while(t>=0){
			if(a[t]==a[i]) break;t=ret[t];
		}
		t++;ret[i+1]=t;
	}
	return ret;
}
class DengklekMessage{
	public:
	double DengklekMessage::theExpected(vector <string> a,vector <string> b,long long c){
		int i,j,k,n=a.size(),m;
		string s="";rep(i,b.size()) s+=b[i];m=s.size();
		vector <int> km=build(s);
		memset(po,0,sizeof(po));
		rep(i,m) rep(j,n){
			int t=i;
			rep(k,a[j].size()){
				while(t>=0){
					if(s[t]==a[j][k]) break;t=km[t];
				}
				t++;if(t>=m){po[i][j]++;t=km[t];}
			}
			next[i][j]=t;
		}
		rep(i,510) rep(j,m){
			if(i<1) dp[i][j]=0.0;
			else{
				rep(k,n) dp[i][j]+=(dp[i-1][next[j][k]]+po[j][k])/n;
			}
		}
		if(c<505LL) return dp[c][0];
		return dp[505][0]+(c-505)*(dp[506][0]-dp[505][0]);
	}
};
