//SRM259DIV1-600 SuperString
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
int st[2550];int dp[2550][2550];
class SuperString{
	public:
	string SuperString::goodnessSubstring(vector <string> A){
		int i,j,n,ma=0;memset(st,-1,sizeof(st));string a="",out="z";
		memset(dp,0,sizeof(dp));
		for(i=0;i<A.size();i++) a+=A[i];n=a.size();
		for(i=0;i<n;i++) for(j=0;j<i;j++){if(a[j]==a[i]) st[i]>?=j;}
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++){
			if(st[j-1]>=i){if(st[st[j-1]]<i) dp[i][j]=dp[i][j-1]-1;else dp[i][j]=dp[i][j-1];}
			else dp[i][j]=dp[i][j-1]+1;
		}
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++) ma>?=dp[i][j];
		for(i=0;i<n;i++){
			int f=0;
			for(j=i+1;j<=n && f<1;j++){
				if(dp[i][j]==ma){f=1;if(out>a.substr(i,j-i)) out=a.substr(i,j-i);}
			}
		}
		return out;
	}
};
