//SRM285DIV1-250 SentenceSplitting
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
int dp[55][55];
class SentenceSplitting{
	public:
	int SentenceSplitting::split(string a,int b){
		vector <int> l;int i,j,k,out=10000;string s;
		istringstream sin(a);while(sin>>s) l.pb(s.size());
		memset(dp,10000,sizeof(dp));dp[0][0]=0;
		for(i=0;i<=b;i++) for(j=0;j<l.size();j++){
			int t=0;
			for(k=j;k<l.size();k++){
				t+=l[k];if(k>j) t++;dp[i+1][k+1]<?=max(dp[i][j],t);
			}
		}
		for(i=1;i<=b+1;i++) out<?=dp[i][l.size()];return out;
	}
};
