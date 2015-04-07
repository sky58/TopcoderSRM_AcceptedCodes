//SRM218DIV1-750 WinningProbability
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double rec(int a,int b){
	double ret=1.0;int i;REP(i,a,b+1) ret*=i;return ret;
}
class WinningProbability{
	public:
	double WinningProbability::probability(int n,int m,int d,int c){
		int i,j;double co[25][25];double out=0.0;
		rep(i,20){
			co[i][0]=co[i][i]=1.0;REP(j,1,i) co[i][j]=co[i-1][j]+co[i-1][j-1];
		}
		REP(i,c,d+1){
			out+=rec(m+1,m+d-i)*rec(n+1,n+m+1)/rec(n+1+i,n+m+d+1)*co[d][i];
		}
		return out;
	}
};
