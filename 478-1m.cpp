//SRM478DIV1-500 KiwiJuice
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
int dp[(1<<15)+10];
class KiwiJuice{
	public:
	int KiwiJuice::theProfit(int m,vector <int> a,vector <int> b){
		int n=a.size(),i,j;memset(dp,0,sizeof(dp));
		for(i=0;i<(1<<n);i++){
			int f=__builtin_popcount(i),t=0;
			for(j=0;j<n;j++){if(i&(1<<j)) t+=a[j];}
			for(j=0;j<f;j++){dp[i]+=b[min(m,t)];t-=min(m,t);}
			for(j=i;j>0;j=(j-1)&i) dp[i]>?=dp[j]+dp[i-j];
		}
		return dp[(1<<n)-1];
	}
};
