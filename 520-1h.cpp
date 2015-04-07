//SRM520DIV1-1000 SRMChallengePhase
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
lint dp[2510][2510];
lint mo=1000000007;
lint cal(int a,int b){
	if(dp[a][b]>=0) return dp[a][b];
	if(b<1) return 1;if(a<=b) return 0;
	return dp[a][b]=(cal(a-1,b)+(a-b)*cal(a-1,b-1))%mo;
}
class SRMChallengePhase{
	public:
	int SRMChallengePhase::countWays(vector <string> a,vector <string> b){
		string c="",d="";int i,j,n,both=0,ing=0,ed=0;
		rep(i,a.size()) c+=a[i];rep(i,b.size()) d+=b[i];
		n=c.size();
		rep(i,n){
			if(c[i]=='Y' && d[i]=='Y') both++;
			else if(c[i]=='Y') ing++;
			else if(d[i]=='Y') ed++;
		}
		if(ed>ing) return 0;
		rep(i,2510) rep(j,2510) dp[i][j]=-1;
		lint out=cal(both+ing,both);
		rep(i,both) out=(out*(i+1))%mo;
		rep(i,ing) out=(out*(i+1))%mo;
		rep(i,ed) out=(out*(ing-i))%mo;
		rep(i,ing-ed) out=(out*(n-1))%mo;
		return (int)(out%mo);
	}
};
