//SRM495DIV2-1000 HexagonPuzzle
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
bool sumi[55][55];
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool un(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
};
class HexagonPuzzle{
	public:
	int HexagonPuzzle::theCount(vector <string> a){
		unionf uni(2550);memset(sumi,false,sizeof(sumi));
		int i,j,k,l,n=a.size();lint out=1,mo=1000000007;vector <lint> zyo;zyo.pb(1);
		for(i=1;i<2600;i++) zyo.pb((zyo[i-1]*i)%mo);
		for(i=0;i<n-1;i++) for(j=0;j<=i;j++){
			if(a[i][j]=='.' && a[i+1][j]=='.' && a[i+1][j+1]=='.'){
				uni.un(i*50+j,i*50+j+50);uni.un(i*50+j,i*50+j+51);
			}
		}
		for(i=0;i<n-1;i++) for(j=0;j<i;j++){
			if(a[i][j]=='.' && a[i][j+1]=='.' && a[i+1][j+1]=='.'){
				uni.un(i*50+j,i*50+j+1);uni.un(i*50+j,i*50+j+51);
			}
		}
		for(i=0;i<n;i++) for(j=0;j<=i;j++){
			if(a[i][j]=='X' || sumi[i][j]) continue;
			int t=0;
			for(k=0;k<n;k++) for(l=0;l<=k;l++){
				if(uni.finds(i*50+j,k*50+l)){sumi[k][l]=true;t++;}
			}
			if(t>1){out=(out*zyo[t])%mo;out=(out*invMod(2,mo))%mo;}
		}
		return (int)(out%mo);
	}
};
