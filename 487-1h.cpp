//SRM487DIV1-950 BunnySequence
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
lint dp1[1100000],dp2[1100000];
lint mo=1000000009;
class BunnySequence{
	public:
	int BunnySequence::getNumber(int m,int n){
		lint out=0;int i,t=-1;dp1[0]=dp2[0]=1;
		for(i=1;i<=1050000;i++){
			dp1[i]=dp2[i-1];if(i>m) dp1[i]=(dp1[i]+mo-dp2[i-m-1])%mo;
			dp2[i]=(dp2[i-1]+dp1[i])%mo;
		}
		out=dp1[n];if(n-m>=0){out=(out+mo+t*dp1[n-m])%mo;t*=-1;}
		//for(i=n-m;i>=0;i-=m){out=(out+mo+t*dp1[i])%mo;t*=-1;}
		return out;
	}
};
