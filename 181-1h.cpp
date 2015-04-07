//SRM181DIV1-1000 KiloManX
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
int ma[20][(1<<15)+10];
class KiloManX{
	public:
	int KiloManX::leastShots(vector <string> a,vector <int> b){
		int n=b.size(),inf=100000000,i,j,k;
		for(i=0;i<20;i++) for(j=0;j<(1<<15)+10;j++) ma[i][j]=1;
		for(i=0;i<(1<<15)+10;i++) dp[i]=inf;dp[0]=0;
		for(i=0;i<n;i++) for(j=0;j<(1<<n);j++) for(k=0;k<n;k++){
			if(j&(1<<k)) ma[i][j]>?=(a[k][i]-'0');
		}
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){
			if(!(i&(1<<j))) dp[i+(1<<j)]<?=dp[i]+(b[j]-1)/ma[j][i]+1;
		}
		return dp[(1<<n)-1];
	}
};
