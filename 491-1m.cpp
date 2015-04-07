//SRM491DIV1-600 PrefixTree
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
int same[(1<<16)+10],dp[(1<<16)+10];int ka[20][30];int mi[30];
class PrefixTree{
	public:
	int PrefixTree::getNumNodes(vector <string> a){
		int n=a.size(),i,j,k;
		memset(same,0,sizeof(same));memset(ka,0,sizeof(ka));memset(dp,10000,sizeof(dp));
		for(i=0;i<n;i++) for(j=0;j<a[i].size();j++) ka[i][(a[i][j]-'a')]++;
		for(i=0;i<(1<<n);i++){
			memset(mi,10000,sizeof(mi));
			for(j=0;j<n;j++){
				if(!(i&(1<<j))) continue;
				for(k=0;k<26;k++) mi[k]<?=ka[j][k];
			}
			for(j=0;j<26;j++){if(mi[j]<10000) same[i]+=mi[j];}
		}
		for(i=0;i<n;i++) dp[(1<<i)]<?=a[i].size();
		for(i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)<=1) continue;
			for(j=i;j>0;j=(j-1)&i){if(j<i) dp[i]<?=dp[j]+dp[i-j]-same[i];}
		}
		return dp[(1<<n)-1]+1;
	}
};
