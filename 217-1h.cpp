//SRM217DIV1-900 TransportAndLoader
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
lint dp[55][55];
vector <int> a;lint b,c;
lint rec(int x,int y){
	lint ret=0,sum=b;int i;
	if(dp[x][y]>-1) return dp[x][y];
	REP(i,x,y){
		ret+=c*a[i];sum+=c*abs(a[i]-a[(x+y)/2]);
	}
	REP(i,x+1,y) ret<?=rec(x,i)+rec(i,y);
	return dp[x][y]=min(sum,ret);
}
class TeleportAndLoader{
	public:
	int TeleportAndLoader::cheapTransportation(vector <int> A,int B,int C){
		a=A;b=B;c=C;sort(All(a));int i,j;
		rep(i,55) rep(j,55) dp[i][j]=-1;return rec(0,a.size());
	}
};
