//SRM534DIV1-1000 EllysString
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
int dp[2550],nex[2550];
class EllysString{
	public:
	int EllysString::theMin(vector <string> a,vector <string> b){
		string c,d;int i,j,n;
		rep(i,a.size()) c+=a[i];rep(i,b.size()) d+=b[i];n=c.size();
		rep(i,n){
			string x=c,y=d;
			REP(j,i,n){
				if(x[j]==y[j]) break;
				if(j>=n-1) continue;
				if(x[j]==y[j+1]){char e=y[j];y[j]=y[j+1];y[j+1]=e;continue;}
				if(y[j]==x[j+1]){char e=x[j];x[j]=x[j+1];x[j+1]=e;continue;}
			}
			nex[i]=j;
		}
		rep(i,2530) dp[i]=10000;dp[0]=0;
		rep(i,n){
			if(nex[i]<n) dp[nex[i]+1]<?=dp[i]+nex[i]-i;dp[i+1]<?=dp[i]+1;
		}
		return dp[n];
	}
};
