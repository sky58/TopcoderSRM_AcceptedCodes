//SRM275DIV1-500 Horoscope
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
int dp[2550][55][3];
class Horoscope{
	public:
	int Horoscope::maxGoodDays(vector <string> a,int b,int c){
		int i,j,out=0;
		string s="";for(i=0;i<a.size();i++) s+=a[i];int n=s.size();
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) for(j=0;j<52;j++){
			int t;
			if(s[i]=='G') t=1;else t=0;
			if(j<b) dp[i+1][j+1][0]>?=dp[i][j][0]+t;
			dp[i+1][1][0]>?=dp[i][j][1]+t;
			if(j<c) dp[i+1][j+1][1]>?=dp[i][j][1]+(t+1)%2;
			dp[i+1][1][1]>?=dp[i][j][0]+(t+1)%2;
		}
		for(i=0;i<52;i++) out>?=max(dp[n][i][0],dp[n][i][1]);return out;
	}
};
