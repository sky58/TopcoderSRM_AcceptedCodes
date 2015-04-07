//SRM521DIV1-1000 Chimney
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

#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <vector <lint> > tmp,one;
vector <lint> cl;
map<lint,vector <vector <lint> > > me;
lint mo=1000000007;
vector <vector <lint> > rec(lint a){
	if(me[a].size()) return me[a];
	int i,j,k;
	vector <vector <lint> > ret=tmp,mae=rec(a/2),ato=rec(a-a/2);
	rep(i,9) rep(j,9) rep(k,9){
		ret[i][j]=(ret[i][j]+mae[i][k]*ato[k][j])%mo;
	}
	return me[a]=ret;
}
class Chimney{
	public:
	int Chimney::countWays(long long a){
		int i;
		rep(i,9) cl.pb(0);rep(i,9) tmp.pb(cl);
		one=tmp;
		one[0][1]=one[1][3]=one[2][3]=one[3][6]=one[4][6]=2;
		one[0][2]=one[1][4]=one[3][5]=one[6][0]=one[6][7]=one[7][1]=one[7][8]=one[8][4]=1;
		one[5][0]=4;
		me[1]=one;return (int)(rec(4*a)[5][5]%mo);
	}
};
