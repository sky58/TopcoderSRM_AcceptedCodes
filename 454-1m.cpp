//SRM454DIV1-500 NumbersAndMatches
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
int te[10]={119,19,93,91,58,107,111,82,127,123};
lint dp[20][150][150];
int keta(lint a){
	if(a==0) return 1;
	int out=0;
	while(a>0){
		a/=10;out++;
	}
	return out;
}
class NumbersAndMatches{
	public:
	long long NumbersAndMatches::differentNumbers(long long a,int n){
		memset(dp,0,sizeof(dp));int i,j,k,l,m=keta(a);lint out=0,hon=0;
		dp[0][0][0]=1;
		for(i=0;i<m;i++){
			int b=a%10;a/=10;hon+=__builtin_popcount(te[b]);
			for(j=0;j<=140;j++) for(k=0;k<=140;k++){
				for(l=0;l<10;l++) dp[i+1][__builtin_popcount(te[l])+j][__builtin_popcount((te[l]&te[b]))+k]+=dp[i][j][k];
			}
		}
		for(i=0;i<=n;i++) out+=dp[m][hon][hon-i];
		return out;
	}
};
