//SRM519DIV1-600 RequiredSubstrings
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
int ed1[8][55][30],ed2[8][55][30],mask[8][55][30];
int dp[55][70][8][55];
class RequiredSubstrings{
	public:
	int RequiredSubstrings::solve(vector <string> a,int C,int L){
		int n=a.size(),i,j,k,l,m,out=0,mo=1000000009;
		for(i=0;i<n;i++) for(j=0;j<=a[i].size();j++) for(k=0;k<26;k++){
			string t=a[i].substr(0,j);t+=('a'+k);
			int x=0,b=0,c=0;
			for(l=0;l<n;l++){
				m=a[l].size();m<?=j+1;
				for(;m>0;m--){
					if(a[l].substr(0,m)==t.substr(j+1-m)) break;
				}
				if(m>b){x=l;b=m;}
				if(j+1>=a[l].size()) if(t.substr(j+1-a[l].size())==a[l]) c|=(1<<l);
			}
			ed1[i][j][k]=x;ed2[i][j][k]=b;mask[i][j][k]=c;
		}
		memset(dp,0,sizeof(dp));dp[0][0][0][0]=1;
		for(i=0;i<L;i++) for(j=0;j<(1<<n);j++) for(k=0;k<n;k++) for(l=0;l<=a[k].size();l++){
			if(dp[i][j][k][l]<1) continue;
			for(m=0;m<26;m++){
				dp[i+1][j|mask[k][l][m]][ed1[k][l][m]][ed2[k][l][m]]+=dp[i][j][k][l];
				dp[i+1][j|mask[k][l][m]][ed1[k][l][m]][ed2[k][l][m]]%=mo;
			}
		}
		for(j=0;j<(1<<n);j++){
			if(__builtin_popcount(j)!=C) continue;
			for(k=0;k<n;k++) for(l=0;l<55;l++) out=(out+dp[L][j][k][l])%mo;
		}
		return out;
	}
};
