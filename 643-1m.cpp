//SRM643DIV1-500 TheKingsArmyDiv1
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
int dp[202][202][3];
int inf=114514;
vector<string> a;
int cal(int x,int y,int z){
	if(dp[x][y][z]>=0) return dp[x][y][z];
	if(z<2){
		int f=0;
		REP(i,x,y){
			if(a[z][i]=='S') f=1;
		}
		if(f<1) return dp[x][y][z]=0;
	}
	int ret=inf;
	if(y>x+1){
		ret=min(ret,min(min(cal(x+1,y,2),cal(x+1,y,z)),min(cal(x,y-1,2),cal(x,y-1,z)))+1);
		REP(i,x+1,y) ret=min(ret,min(cal(x,i,2),cal(x,i,z))+min(cal(i,y,2),cal(i,y,z)));
	}
	if(z==2){
		ret=min(ret,min(cal(x,y,0),cal(x,y,1))+1);
		ret=min(ret,cal(x,y,0)+cal(x,y,1));
	}
	//cout<<x<<' '<<y<<' '<<z<<' '<<ret<<endl;
	return dp[x][y][z]=ret;
}
class TheKingsArmyDiv1{
	public:
	int getNumber(vector<string> A){
		a=A;
		rep(i,202) rep(j,202) rep(k,3) dp[i][j][k]=-1;
		int n=a[0].size(),out=cal(0,n,2);
		if(out>inf/2) return -1;return out;
	}
};
