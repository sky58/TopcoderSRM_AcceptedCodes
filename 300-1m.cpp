//SRM300DIV1-500 JumpyNum
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
int dp[15][12];
string de(int a){
	string ret="";while(a>0){ret+=((a%10)+'0');a/=10;}return ret;
}
bool ch(string a){
	int i,n=a.size();
	for(i=0;i<n-1;i++){
		if(abs((a[i]-'0')-(a[i+1]-'0'))<2) return false;
	}
	return true;
}
int cal(string a){
	int n=a.size(),i,j,ret=0;
	for(i=0;i<n;i++){
		for(j=0;j<=(a[i]-'0');j++){
			if(i>0 && j==(a[i]-'0')) continue;if(i==n-1 && j==0) continue;
			string b="";b+=(j+'0');if(i<n-1) b+=a.substr(i+1,n-i-1);if(ch(b)) ret+=dp[i][j];
		}
	}
	for(i=1;i<=9;i++) for(j=0;j<n-1;j++) ret+=dp[j][i];return ret;
}
class JumpyNum{
	public:
	int JumpyNum::howMany(int a,int b){
		int i,j,k;
		memset(dp,0,sizeof(dp));for(i=0;i<10;i++) dp[0][i]=1;
		for(i=0;i<13;i++) for(j=0;j<10;j++) for(k=0;k<10;k++){
			if(abs(j-k)>1) dp[i+1][k]+=dp[i][j];
		}
		if(a==1) return cal(de(b));return cal(de(b))-cal(de(a-1));
	}
};
