//SRM607DIV1-250 PalindromicSubstringsDiv1
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
double dp[5010][5010];
string x="";
double cal(int a,int b){
	if(b<=a) return 1.0;
	if(dp[a][b]>-0.5) return dp[a][b];
	if(x[a]=='?' || x[b]=='?') return dp[a][b]=cal(a+1,b-1)/26;
	else if(x[a]!=x[b]) return dp[a][b]=0.0;
	else return dp[a][b]=cal(a+1,b-1);
}
class PalindromicSubstringsDiv1{
	public:
	double expectedPalindromes(vector<string> a,vector<string> b){
		rep(i,a.size()) x+=a[i];rep(j,b.size()) x+=b[j];
		int n=x.size();double out=0.0;
		rep(i,5010) rep(j,5010) dp[i][j]=-1.0;
		rep(i,n) REP(j,i,n) out+=cal(i,j);
		return out;
	}
};
