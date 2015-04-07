//SRM320DIV1-1000 SeatingPlan
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
lint dp[85][25][300];
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
string moji(lint a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class SeatingPlan{
	public:
	string SeatingPlan::expectedTrial(int x,int y,int z){
		if(x>y){int d=x;x=y;y=d;}int i,j,k;lint ret=0,re=1,ko;
		for(i=0;i<300;i++) for(j=0;j<85;j++) for(k=0;k<25;k++) dp[j][k][i]=0;dp[0][0][0]=1;
		for(i=0;i<x*y;i++) for(k=0;k<(1<<x);k++) for(j=0;j<=z;j++){
			int h=i%x;dp[i+1][j][(k|(1<<h))-(1<<h)]+=dp[i][j][k];
			if(k&(1<<h)) continue;if(h>0) if(k&(1<<(h-1))) continue;
			dp[i+1][j+1][k|(1<<h)]+=dp[i][j][k];
		}
//		lint a=3535316142212174320LL,b=6545003086544LL;cout<<a%b<<endl;
		for(i=0;i<(1<<x);i++) ret+=dp[x*y][z][i];if(ret==0) return "Impossible!";
		for(i=1;i<=z;i++){
			lint ka=gcd(re,i);
			re=re/ka*(x*y-i+1)/(i/ka);
		}
//		cout<<re<<' '<<ret<<endl;
		ko=gcd(re,ret);re/=ko;ret/=ko;
		return moji(re)+'/'+moji(ret);
	}
};
