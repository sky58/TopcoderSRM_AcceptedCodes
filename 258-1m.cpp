//SRM258DIV1-500 CompressionText
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
int dp[55];
class CompressionText{
	public:
	int CompressionText::shortestLength(string a){
		int n=a.size(),out=n,i,j,k;
		if(n<3) return out;if(n<6) return n-1;
		for(i=0;i<n-5;i++) for(j=i+3;j<n-2;j++){
			string x=a.substr(i,3),y=a.substr(j,3);
			memset(dp,100,sizeof(dp));dp[0]=0;
			for(k=0;k<n;k++){
				if(k<n-2) if(a.substr(k,3)==x || a.substr(k,3)==y) dp[k+3]<?=dp[k]+2;dp[k+1]<?=dp[k]+1;
			}
			out<?=dp[n];
		}
		return out;
	}
};
