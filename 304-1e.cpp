//SRM304DIV1-300 PolyMove
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
double dp[55][3],s[55];
class PolyMove{
	public:
	double PolyMove::addedArea(vector <int> x,vector <int> y){
		double out=0.0;int i,j,n=x.size();
		for(j=0;j<n;j++) s[j]=0.5*sqrt((x[(j+1)%n]-x[(j+n-1)%n])*(x[(j+1)%n]-x[(j+n-1)%n])+(y[(j+1)%n]-y[(j+n-1)%n])*(y[(j+1)%n]-y[(j+n-1)%n]));
		for(i=0;i<55;i++) for(j=0;j<3;j++) dp[i][j]=0.0;
		for(i=1;i<n;i++){dp[i][1]>?=dp[i-1][0]+s[i];dp[i][0]>?=max(dp[i-1][0],dp[i-1][1]);}out>?=max(dp[n-1][0],dp[n-1][1]);
		for(i=0;i<55;i++) for(j=0;j<3;j++) dp[i][j]=0.0;
		for(i=2;i<n-1;i++){dp[i][1]>?=dp[i-1][0]+s[i];dp[i][0]>?=max(dp[i-1][0],dp[i-1][1]);}out>?=s[0]+max(dp[n-2][0],dp[n-2][1]);
		return out;
	}
};
