//SRM257DIV1-1000 Computers
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
lint dp[1100][1100];int d;
lint cal(int a,int b){
	if(b<0) return 0;if(b==0) return 1;if(a==0) return 0;if(dp[a][b]>-1) return dp[a][b];
	int i;lint ret=0;ret+=cal(a-1,b);
	for(i=0;(i+d)*a<=b;i++) ret+=cal(a-1,b-(i+d)*a);return dp[a][b]=ret;
}
class Computers{
	public:
	long long Computers::choices(int n,int D,int b,int c){
		int i,j;d=D;lint out=0;
		for(i=0;i<1100;i++) for(j=0;j<1100;j++) dp[i][j]=-1;
		for(i=b;i<1050;i++) out+=cal(c-1,n-i*c);return out;
	}
};
