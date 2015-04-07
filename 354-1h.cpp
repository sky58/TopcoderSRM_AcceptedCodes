//SRM354DIV1-900 RooksPlasement
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
typedef long long Int;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[52][52][52][52];
lint mo=1000001;
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
int rec(int a,int b,int c,int d,int e){
	if(dp[a][b][c][d]>-1) return dp[a][b][c][d];
	if(a<0 || b<0 || c<0 || d<0) return 0;if(e==0) return 1;
	lint ret=0;
	if(a*c>0) ret=(ret+(lint)rec(a-1,b+1,c-1,d+1,e-1)*a*c)%mo;
	if(b*c>0) ret=(ret+(lint)rec(a,b-1,c-1,d-1,e-1)*b*c)%mo;
	if(a*d>0) ret=(ret+(lint)rec(a-1,b-1,c,d-1,e-1)*a*d)%mo;
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<ret<<endl;
	return dp[a][b][c][d]=(int)(ret%mo);
}
class RooksPlacement{
	public:
	int RooksPlacement::countPlacements(int x,int y,int z){
		int i,j,k,l;
		for(i=0;i<52;i++) for(j=0;j<52;j++) for(k=0;k<52;k++) for(l=0;l<52;l++) dp[i][j][k][l]=-1;
		lint a=rec(x,0,y,0,z);//cout<<a<<endl;
		for(i=1;i<=z;i++) a=(a*invMod(i,mo))%mo;return (int)(a%mo);
	}
};
