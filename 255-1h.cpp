//SRM255DIV1-800 OddDigits
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
vector <int> zyo;
bool dp[210][100010];
class OddDigitable{
	public:
	string OddDigitable::findMultiple(int mo,int a){
		int i,j,k,t;string out="";
		memset(dp,false,sizeof(dp));dp[0][0]=true;
		for(i=1;i<210;i++) for(j=0;j<mo;j++) for(k=1;k<10;k+=2){
			if(dp[i-1][j]) dp[i][(j*10+k)%mo]=true;
		}
		zyo.pb(1);for(i=0;i<210;i++) zyo.pb((zyo[i]*10)%mo);
		for(t=1;t<210;t++){
			if(dp[t][a]) break;
		}
		if(t>=210) return "-1";
		for(i=0;i<t;i++){
			for(j=1;j<10;j+=2){
				if(dp[t-i-1][(mo*100+a-zyo[t-i-1]*j)%mo]) break;
			}
			out+=('0'+j);a=(mo*100+a-zyo[t-i-1]*j)%mo;
		}
		return out;
	}
};
