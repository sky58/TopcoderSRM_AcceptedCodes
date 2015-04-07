//SRM483DIV1-500 Bribes
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
vector <int> a,b;
int dp[55][(1<<17)+50];
bool ch(int x,int y){
	int i,t=0;
	for(i=0;i<17;i++){
		if(!(y&(1<<i))) continue;
		int s=i-8;t+=a[x+s]/(1<<abs(s));
	}
//	cout<<x<<' '<<y<<' '<<t<<endl;
	if(b[x]<=t) return true;return false;
}
class Bribes{
	public:
	int Bribes::minBribes(vector <int> A,vector <int> B){
		int i,j,out=1000,n=A.size();//memset(dp,1000,sizeof(dp));
		for(i=0;i<55;i++) for(j=0;j<(1<<17)+30;j++) dp[i][j]=1000;
		for(i=0;i<10;i++) a.pb(0);for(i=0;i<n;i++) a.pb(A[i]);for(i=0;i<10;i++) a.pb(0);
		for(i=0;i<10;i++) b.pb(0);for(i=0;i<n;i++) b.pb(B[i]);for(i=0;i<10;i++) b.pb(0);
		for(i=0;i<(1<<17);i++) dp[0][i]=__builtin_popcount(i);
		for(i=0;i<n;i++) for(j=0;j<(1<<17);j++){
			if(dp[i][j]>=1000) continue;
			if(!ch(10+i,j)) continue;
//			cout<<i<<' '<<j<<endl;
			dp[i+1][j/2]<?=dp[i][j];dp[i+1][(j/2)+(1<<16)]<?=dp[i][j]+1;
		}
		for(i=0;i<(1<<17);i++) out<?=dp[n][i];if(out>=1000) return -1;return out;
	}
};
