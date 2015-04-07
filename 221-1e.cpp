//SRM221DIV1-250 TerribleEncryption
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
typedef int Int;
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
class TerribleEncryption{
	public:
	string TerribleEncryption::decrypt(string a,vector <int> b,vector <int> c){
		string out="";int n=b.size(),m=a.size(),i;
		for(i=0;i<n;i++){
			int t=invMod(b[i],c[i]);out+=a[t%m];
		}
		return out;
	}
};
