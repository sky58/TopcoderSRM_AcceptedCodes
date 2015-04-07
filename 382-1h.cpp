//SRM382DIV1-1000 CharmingTickets

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
class CharmingTickets{
	public:
	int CharmingTickets::count(int n,string ff){
		vector <int> f;int dp[4502][502];int d[9010];
		int out=0,a=n/2,b=n-n/2,i,j,k,mo=999983,c=b*9,ou=0;
		
		for(i=0;i<10;i++) f.push_back(0);
		for(i=0;i<ff.size();i++) f[(ff[i]-'0')]=1;
		memset(dp,0,sizeof(dp));dp[0][0]=1;memset(d,0,sizeof(d));
		for(i=1;i<=b;i++) for(j=0;j<=c;j++) for(k=0;k<10 && k<=j;k++){
			dp[j][i]+=dp[j-k][i-1]*f[k];dp[j][i]%=mo;
		}
		
		for(i=0;i<=c;i++) for(j=0;j<=c;j++){
			long long t=(long long)dp[i][a]*dp[j][b]%mo;
			d[i+j]=(d[i+j]+(int)t)%mo;t*=t;t%=mo;out=(out+(int)t)%mo;
		}
		for(i=0;i<=n*9;i++){ou+=(int)((long long)d[i]*d[i]%mo);ou%=mo;}
		ou*=2;
		
		return (ou+mo-out)%mo;
	}
};
