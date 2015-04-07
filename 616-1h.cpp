//SRM616DIV1-1000 ThreeLLogo
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MAXC 4096
vector<int> bitid;
lint dp[902][MAXC][4][2];
int w,h;
vector<string> a;
lint cal(int x,int y,int mask,int b,int c){
	if(y>=w) return cal(x+1,0,mask,b+c,0);
	if(x>=h){if(b>=3) return 1;return 0;}
	int bit=lower_bound(All(bitid),mask)-bitid.begin(),now=x*w+y;
	lint ret=0;
	if(dp[now][bit][b][c]>=0) return dp[now][bit][b][c];
	//ñÑÇ‹Ç¡ÇƒÇ¢ÇÈèÍçá
	if(a[x][y]=='#'){
		if((mask&(1<<y))) return dp[now][bit][b][c]=0;
		return dp[now][bit][b][c]=cal(x,y+1,mask,b+c,0);
	}
	//ã»Ç∞ÇÈèÍçá
	if(y<w-1 && a[x][y+1]=='.' && (mask&(1<<y)) && !(mask&(1<<(y+1)))){
		ret+=cal(x,y+2,mask-(1<<y),b+c,1);
	}
	//LéöÇêLÇŒÇ∑èÍçá
	if(c>0){if(!(mask&(1<<y))) ret+=cal(x,y+1,mask,b,1);}
	//êVÇΩÇ…í«â¡Ç∑ÇÈèÍçá
	if(y<w-1 && !(mask&(1<<y)) && __builtin_popcount(mask)+b+c<3){
		ret+=cal(x,y+1,mask+(1<<y),b+c,0);
	}
	ret+=cal(x,y+1,mask,b+c,0);
	//if(ret>0) cout<<x<<' '<<y<<' '<<mask<<' '<<b<<' '<<c<<' '<<ret<<endl;
	return dp[now][bit][b][c]=ret;
}
class ThreeLLogo{
	public:
	long long countWays(vector<string> A){
		a=A;h=a.size();w=a[0].size();
		bitid.pb(0);
		rep(i,w-1){
			bitid.pb((1<<i));
			REP(j,i+1,w-1){
				bitid.pb((1<<i)+(1<<j));
				REP(k,j+1,w-1){
					bitid.pb((1<<i)+(1<<j)+(1<<k));
				}
			}
		}
		sort(All(bitid));bitid.erase(unique(All(bitid)),bitid.end());
		memset(dp,-1,sizeof(dp));
		return cal(0,0,0,0,0);
	}
};
