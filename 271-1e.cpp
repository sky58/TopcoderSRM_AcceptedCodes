//SRM271DIV1-250 OneFight
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
int dp[(1<<10)+10],da[(1<<10)+10];
class OneFight{
	public:
	int OneFight::monsterKilling(vector <int> a,vector <int> b,int c){
		int n=a.size(),i,j;memset(da,0,sizeof(da));
		for(i=0;i<1030;i++) dp[i]=1000000000;dp[0]=0;
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){if(i&(1<<j)) da[i]+=b[j];}
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){
			if(i&(1<<j)) continue;dp[i+(1<<j)]<?=dp[i]+((a[j]-1)/c+1)*da[(1<<n)-1-i];
		}
		return dp[(1<<n)-1]+1;
	}
};
