//SRM358DIV1-500 BalanceScale
#include<stdio.h>
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
#include<list>
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
int dp[10000010];
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class BalanceScale{
	public:
	int BalanceScale::takeWeights(vector <int> a){
		int i,n=a.size(),g=a[0];queue <int> Q;
		for(i=0;i<10000010;i++) dp[i]=200;
		for(i=1;i<n;i++) g=gcd(g,a[i]);
		for(i=0;i<n;i++) a[i]/=g;
		for(i=0;i<n;i++){Q.push(a[i]);dp[a[i]]<?=1;}
		while(dp[1]>100){
			int t=Q.front();Q.pop();
			for(i=0;i<n;i++){
				int s=gcd(a[i],t);if(dp[s]<100) continue;
				dp[s]<?=dp[t]+1;Q.push(s);
			}
		}
		return dp[1];
	}
};
