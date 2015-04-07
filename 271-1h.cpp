//SRM271DIV1-1000 ConvexHull
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
int dp[220][220];vector <int> x,y;
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class ConvexHull{
	public:
	int ConvexHull::intHull(int a,int b){
		int i,j,k,out=0;
		for(i=1;i<210;i++) for(j=0;j<210;j++){
			if(gcd(i,j)==1){x.pb(i);y.pb(j);}
		}
		for(i=0;i<x.size();i++) for(j=205;j>=x[i];j--) for(k=205;k>=y[i];k--) dp[j][k]>?=dp[j-x[i]][k-y[i]]+1;
		for(i=1;i<210;i++) for(j=0;j<210;j++) dp[i][j]>?=max(dp[i-1][j],dp[i][j-1]);
		for(i=0;i<=a;i++) for(j=0;j<=a;j++){
			int t1=0,t2=0;
			for(k=0;k<=b;k++){
				t1>?=dp[a-i][k]+dp[b-k][a-j];t2>?=dp[j][b-k]+dp[k][i];
			}
			out>?=t1+t2;
		}
		return out;
	}
};
