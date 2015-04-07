//SRM411DIV1-250 SentenceDecomposition
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
int dp[110];
int com(string a,string b){
	string c=a,d=b;int i,ret=0,n=a.size();
	sort(c.begin(),c.end());sort(d.begin(),d.end());
	if(c!=d) return 10000;
	for(i=0;i<n;i++){if(a[i]!=b[i]) ret++;}
	return ret;
}
class SentenceDecomposition{
	public:
	int SentenceDecomposition::decompose(string a,vector <string> b){
		int n=a.size(),m=b.size(),i,j;
		for(i=0;i<110;i++) dp[i]=10000;dp[0]=0;
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			int c=b[j].size();
			if(i+c<=n) dp[i+c]<?=dp[i]+com(a.substr(i,c),b[j]);
		}
		if(dp[n]>5000) return -1;return dp[n];
	}
};
