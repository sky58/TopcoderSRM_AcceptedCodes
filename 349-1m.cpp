//SRM349DIV1-500 DiceGames
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
typedef long long lint;
lint dp[50][50];
class DiceGames{
	public:
	long long DiceGames::countFormations(vector <int> a){
		int i,j,k,n=a.size();lint out=0;
		sort(a.begin(),a.end());memset(dp,0,sizeof(dp));dp[0][1]=1;
		for(i=0;i<n;i++) for(j=1;j<=a[i];j++) for(k=1;k<=j;k++) dp[i+1][j]+=dp[i][k];
		for(i=0;i<40;i++) out+=dp[n][i];
		return out;
	}
};
