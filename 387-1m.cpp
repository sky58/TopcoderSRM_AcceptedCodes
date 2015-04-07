//SRM387DIV1-500 IntervalSubsets
#include<stdio.h>
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
#include<list>
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[105];int aru[105][105];
bool sai[105][105];
class IntervalSubsets{
	public:
	int IntervalSubsets::numberOfSubsets(vector <int> a,vector <int> b){
		int i,j,k,out=0,n=a.size();
		memset(dp,0,sizeof(dp));memset(aru,0,sizeof(aru));memset(sai,false,sizeof(sai));
		dp[0]=1;
		for(i=0;i<n;i++){
			aru[a[i]][b[i]]++;
			for(j=0;j<a[i];j++) for(k=b[i]+1;k<105;k++) sai[j][k]=true;
		}
		for(i=1;i<103;i++) for(j=1;j<=i;j++){
			if(aru[j][i]==0) continue;
			for(k=0;k<j;k++){
				if(!sai[k][j]) dp[i]+=aru[j][i]*dp[k];
			}
		}
		for(i=0;i<103;i++){
			if(!sai[i][104]) out+=dp[i];
		}
		return out;
	}
};
