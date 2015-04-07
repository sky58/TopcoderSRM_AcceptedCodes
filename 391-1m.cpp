//SRM391DIV1-500 KeyInBoxes

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
using namespace std;

long long gcd(long long m, long long n )
{
	long long a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}

string moji(long long a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}

class KeysInBoxes{
	public:
	string KeysInBoxes::getAllKeys(int n,int m){
		int i,j;long long a=0,b=1,t;
		long long dp[30][30];
		memset(dp,0,sizeof(dp));dp[0][0]=1;
		
		for(i=1;i<=n;i++) for(j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j-1]+(i-1)*dp[i-1][j];
		}
		for(i=1;i<=m;i++) a+=dp[n][i];for(i=1;i<=n;i++) b*=i;
//		return moji(a);
		t=gcd(a,b);a/=t;b/=t;
		return moji(a)+'/'+moji(b);
	}
};
