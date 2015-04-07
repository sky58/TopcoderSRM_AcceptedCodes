//SRM308DIV1-1000 Wardrobe
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
int dp[55][2];
int ka[55][55][2];
int me[110];
int ca0(vector <int> b){
	int i,n=b.size(),ret=0;
	memset(me,0,sizeof(me));
	for(i=0;i<n;i++) me[b[i]]++;
	for(i=0;i<n;i++){
		if(me[b[i]+1]>0) me[b[i]+1]--;
		else if(me[b[i]]>0) me[b[i]]--;
		else if(me[b[i]-1]>0) me[b[i]-1]--;
		else ret++;
	}
	return ret;
}
int ca1(vector <int> b){
	int i,n=b.size(),ret=0;
	memset(me,0,sizeof(me));reverse(b.begin(),b.end());
	for(i=0;i<n;i++) me[b[i]]++;
	for(i=0;i<n;i++){
		if(me[b[i]-1]>0) me[b[i]-1]--;
		else if(me[b[i]]>0) me[b[i]]--;
		else if(me[b[i]+1]>0) me[b[i]+1]--;
		else ret++;
	}
	return ret;
}
class Wardrobe{
	public:
	int Wardrobe::countUnscrewedHoles(vector <int> a){
		int i,j,k,n=a.size();
		sort(a.begin(),a.end());memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++){
			vector <int> b;for(k=i;k<j;k++) b.pb(a[k]);
			ka[i][j][0]=ca0(b);ka[i][j][1]=ca1(b);
		}
		for(i=1;i<=n;i++){dp[i][0]>?=ka[0][i][0];dp[i][1]>?=ka[0][i][1];}
		for(i=1;i<n;i++) for(j=i+1;j<=n;j++){
			dp[j][0]>?=dp[i][1]+ka[i][j][0];dp[j][1]>?=dp[i][0]+ka[i][j][1];
			if(a[i]-a[i-1]>1){dp[j][0]>?=dp[i][0]+ka[i][j][0];dp[j][1]>?=dp[i][1]+ka[i][j][1];}
		}
		return max(dp[n][0],dp[n][1]);
	}
};
