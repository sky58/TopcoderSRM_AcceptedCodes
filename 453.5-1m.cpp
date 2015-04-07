//SRM453.5DIV1-450 PlanarGraphShop
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
int dp[55000];
class PlanarGraphShop{
	public:
	int PlanarGraphShop::bestCount(int n){
		vector <int> ka,ki;int i,j;
		for(i=0;i<55000;i++) dp[i]=55000;dp[0]=0;
		ka.pb(8);ka.pb(9);ka.pb(1);
		for(i=3;i*i*i<=55000;i++) for(j=0;j<=i*3-6 && i*i*i+j*j<=55000;j++) ka.pb(i*i*i+j*j);
		sort(ka.begin(),ka.end());ki.pb(ka[0]);
		for(i=1;i<ka.size();i++){
			if(ka[i]!=ka[i-1]) ki.pb(ka[i]);
		}
		for(i=0;i<=n;i++) for(j=0;i+ki[j]<=n;j++) dp[i+ki[j]]<?=dp[i]+1;
		return dp[n];
	}
};
