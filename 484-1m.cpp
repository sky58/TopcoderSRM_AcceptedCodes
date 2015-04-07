//SRM484DIV1-500 PuyoPuyo
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
lint dp[1100][1100];int l,mo=1000000007;
lint cal(int a,int b){
	if(b>a) return 0;
	if(dp[a][b]>=0) return dp[a][b];
	if(a==0) return 1;
	lint ret=0;
	if(b==0) ret+=4*cal(a-1,l-1);else ret+=(cal(a-1,b-1)+3*cal(a-1,b+l-1));
	return dp[a][b]=ret%mo;
}
class PuyoPuyo{
	public:
	int PuyoPuyo::theCount(int L,int n){
		l=L;memset(dp,-1,sizeof(dp));return (int)(cal(n,0)%mo);
	}
};
