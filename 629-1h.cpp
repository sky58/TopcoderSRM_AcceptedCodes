//SRM629DIV1-950 CandyDrawing
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
lint dp[4010][2010];lint d2[4010];
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
class CandyDrawing{
	public:
	int findProbability(int n,int k,int mo){
		lint out=0,f=1;
		memset(dp,0,sizeof(dp));dp[0][0]=1;
		rep(i,k*2) rep(j,k+1){
			dp[i][j]%=mo;
			dp[i+1][j]+=dp[i][j];
			dp[i+1][j+1]+=dp[i][j]*(i+1);
		}
		rep(i,k*2+1) d2[i]=dp[i][k];
		rep(i,k*2+1){
			lint t=d2[0];
			rep(j,i) t=(t*(n-j))%mo;
			out=(out+(t*invMod(f,mo)))%mo;
			f=(f*(i+1))%mo;
			rep(j,k*2) d2[j]=(mo+d2[j+1]-d2[j])%mo;
		}
		return (int)(out%mo);
	}
};
