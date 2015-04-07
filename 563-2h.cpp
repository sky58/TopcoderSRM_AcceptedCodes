//SRM563DIV2-1000 SpellCardsEasy
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
class SpellCardsEasy{
	public:
	int SpellCardsEasy::maxDamage(vector <int> l,vector <int> d){
		int n=l.size(),i,j,out=0;int dp[55][55];
		rep(i,55) rep(j,55) dp[i][j]=-1000000000;dp[n][0]=0;
		for(i=n-1;i>=0;i--) rep(j,n){
			if(l[i]<=j+1) dp[i][j+1-l[i]]>?=dp[i+1][j]+d[i];
			dp[i][j+1]>?=dp[i+1][j];
		}
		rep(i,n+1) out>?=dp[0][i];
		return out;
	}
};
