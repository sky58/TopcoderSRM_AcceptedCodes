//SRM528DIV1-500 SPartition
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[22][22];
class SPartition{
	public:
	long long SPartition::getCount(string a){
		int o=0,x=0,n=a.size(),i,j;lint out=0;string s="";
		rep(i,n){
			if(a[i]=='x') x++;else o++;
		}
		if(o%2>0 || x%2>0) return 0;
		rep(i,o/2) s+='o';rep(i,x/2) s+='x';
		while(1){
			rep(i,22) rep(j,22) dp[i][j]=0;dp[0][0]=1;
			rep(i,n/2+1) rep(j,n/2+1){
				if(a[i+j]==s[i]) dp[i+1][j]+=dp[i][j];
				if(a[i+j]==s[j]) dp[i][j+1]+=dp[i][j];
			}
			out+=dp[n/2][n/2];
			if(!next_permutation(All(s))) break;
		}
		return out;
	}
};
