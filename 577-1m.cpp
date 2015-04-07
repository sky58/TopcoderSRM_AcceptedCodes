//SRM577DIV1-500 EllysChessboard
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
int dp[20][20][20][20];
bool in(int xl,int x,int xh,int yl,int y,int yh){
	return (xl<=x && x<=xh && yl<=y && y<=yh);
}
int cal(int xl,int x,int xh,int yl,int y,int yh){
	return max(max(abs(x-xl),abs(x-xh)),max(abs(y-yl),abs(y-yh)));
}
class EllysChessboard{
	public:
	int minCost(vector<string> a){
		int inf=114514,x=14,y=0,z=14,w=0;
		rep(i,20) rep(j,20) rep(k,20) rep(l,20) dp[i][j][k][l]=inf;
		string s(15,'.');
		vector<string> b(15,s);
		rep(i,8) rep(j,8){
			int x=i+j,y=i-j+7;
			b[x][y]=a[i][j];
		}
		rep(i,15) rep(j,15){
			if(b[i][j]=='#'){
				dp[i][i][j][j]=0;
				x=min(x,i);y=max(y,i);z=min(z,j);w=max(w,j);
			}
		}
		if(x>y) return 0;
		rep(i,15) rep(k,15) rep(j,15-i) rep(l,15-k){
			int xl=j,xh=j+i,yl=l,yh=l+k;
			if(dp[xl][xh][yl][yh]>=inf) continue;
			rep(m,15) rep(n,15){
				if(!in(xl,m,xh,yl,n,yh) && b[m][n]=='#'){
					int nv=dp[xl][xh][yl][yh]+cal(xl,m,xh,yl,n,yh),xl2=min(xl,m),xh2=max(xh,m),yl2=min(yl,n),yh2=max(yh,n);
					REP(o,xl2,xh2+1) REP(p,yl2,yh2+1){
						if((o!=m || p!=n) && !in(xl,o,xh,yl,p,yh) && b[o][p]=='#') nv+=cal(xl2,o,xh2,yl2,p,yh2);
					}
					dp[xl2][xh2][yl2][yh2]=min(dp[xl2][xh2][yl2][yh2],nv);
				}
			}
		}
		return dp[x][y][z][w];
	}
};
