//SRM500DIV1-1000 ProductAndSum
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
typedef long long Int;
int p[12];
lint mo=500500573,bo;
lint co[2510][2510];
vector <lint> zyo,inv;
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
class ProductAndSum{
	public:
	int ProductAndSum::getSum(int p2,int p3,int p5,int p7,int s){
		int i,j;lint out=0;bo=((1LL<<63)-1)/mo;
		memset(p,0,sizeof(p));p[5]=p5;p[7]=p7;
		zyo.pb(1);for(i=0;i<2510;i++) zyo.pb((zyo[i]*10+1)%mo);inv.pb(0);
		for(i=1;i<2510;i++) inv.pb(invMod(i,mo));
		for(i=0;i<2510;i++) for(j=0;j<=i;j++){
			if(j<1 || j==i) co[i][j]=1;else co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		for(p[8]=0;p[8]*3<=p2;p[8]++) for(p[9]=0;p[9]*2<=p3;p[9]++) for(p[4]=0;p[4]*2+p[8]*3<=p2;p[4]++){
			for(p[6]=0;p[6]+p[9]*2<=p3 && p[6]+p[4]*2+p[8]*3<=p2;p[6]++){
				p[2]=p2-p[8]*3-p[4]*2-p[6];p[3]=p3-p[9]*2-p[6];
				int t=0,d=0,d1;lint k=1;for(i=2;i<10;i++) t+=p[i]*i;if(t>s) continue;p[1]=s-t;
				for(i=1;i<10;i++) d+=p[i];d1=d;
				for(i=1;i<10;i++){k=(k*co[d][p[i]])%mo;d-=p[i];}
				for(i=1;i<10;i++){if(p[i]<1) continue;out=((zyo[d1-1]*i*k)%mo*((p[i]*inv[d1])%mo)+out)%mo;}
			}
		}
		return (int)(out%mo);
	}
};
