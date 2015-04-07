//SRM248DIV1-250 WordPattern
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
lint dp[55][55];
class WordPattern{
	public:
	long long WordPattern::countWords(string a){
		int i,j,n=a.size();lint out=0;
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=0;dp[0][0]=1;
		for(i=0;i<n-1;i++) for(j=0;i+j<n-1;j++){
			dp[i+1][j]+=dp[i][j];dp[i][j+1]+=dp[i][j];
			if(i<1) dp[i+1][j]+=dp[i][j];
			if(j<1) dp[i][j+1]+=dp[i][j];
		}
		for(i=0;i<n;i++) out+=dp[i][n-i-1];return out;
	}
};
