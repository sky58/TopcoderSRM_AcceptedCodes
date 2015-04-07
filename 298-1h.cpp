//SRM298DIV1-1000 CountingCommonSubsequences
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
lint dp[55][55][55][30];
class CountingCommonSubsequences{
	public:
	long long CountingCommonSubsequences::countCommonSubsequences(string a,string b,string c){
		int i,j,k,l,la=a.size(),lb=b.size(),lc=c.size(),m;lint out=0;
		for(i=0;i<55;i++) for(j=0;j<55;j++) for(k=0;k<55;k++) for(l=0;l<30;l++) dp[i][j][k][l]=0;
		for(i=1;i<=la;i++) for(j=1;j<=lb;j++) for(k=1;k<=lc;k++) for(l=0;l<26;l++){
			if(a[i-1]!=('a'+l)){dp[i][j][k][l]=dp[i-1][j][k][l];continue;}
			if(b[j-1]!=('a'+l)){dp[i][j][k][l]=dp[i][j-1][k][l];continue;}
			if(c[k-1]!=('a'+l)){dp[i][j][k][l]=dp[i][j][k-1][l];continue;}
			for(m=0;m<26;m++) dp[i][j][k][l]+=dp[i-1][j-1][k-1][m];dp[i][j][k][l]++;
		}
		for(i=0;i<26;i++) out+=dp[la][lb][lc][i];return out;
	}
};
