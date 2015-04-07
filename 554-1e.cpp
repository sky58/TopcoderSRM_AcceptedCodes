//SRM554DIV1-250 TheBrickTowerEasyDivOne
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class TheBrickTowerEasyDivOne{
	public:
	int TheBrickTowerEasyDivOne::find(int rc,int rh,int bc,int bh){
		if(bh==rh){
			if(rc==bc) return rc*2;
			else return min(rc,bc)*2+1;
		}
		else{
			if(rc==bc) return rc*3;
			else return min(rc,bc)*3+1;
		}
	}
};
