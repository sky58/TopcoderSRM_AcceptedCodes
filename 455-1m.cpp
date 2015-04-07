//SRM455DIV1-550 ConvexHexagons
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
lint dp[510000],zyok[510000],com[510000],comk[510000];
lint mo=1000000007;
class ConvexHexagons{
	public:
	int ConvexHexagons::find(int a){
		if(a<3) return 0;int i;
		zyok[3]=1;for(i=4;i<505000;i++) zyok[i]=(zyok[i-1]+(lint)(i-2)*(i-2))%mo;
		com[1]=1;for(i=2;i<505000;i++) com[i]=(com[i-1]+i)%mo;
		comk[3]=0;comk[4]=1;for(i=5;i<505000;i++) comk[i]=(comk[i-2]+com[i-3])%mo;
		dp[0]=0;dp[1]=0;dp[2]=0;for(i=3;i<505000;i++) dp[i]=(3*dp[i-1]+zyok[i]+mo*5-comk[i]-3*dp[i-2]+dp[i-3])%mo;
		return dp[a]%mo;
	}
};
