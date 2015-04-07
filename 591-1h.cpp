//SRM591DIV1-900 StringPath
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
lint dp[70][260][260];
int mo=1000000009;
class StringPath{
	public:
	int countBoards(int n,int m,string a,string b){
		vector <lint> zyo;zyo.pb(1);rep(i,70) zyo.pb((zyo[i]*26)%mo);
		dp[0][1][1]=1;lint out=0;
		rep(i,n*m) rep(j,(1<<m)) rep(k,(1<<m)){
			dp[i][j][k]%=mo;
			int x=i/m,y=i%m,n1=1,n2=1;
			if((j&(1<<y)) || (y>0 && (j&(1<<(y-1))))) n1=0;
			if((k&(1<<y)) || (y>0 && (k&(1<<(y-1))))) n2=0;
			if(a[x+y]==b[x+y]){
				dp[i+1][(j|(1<<y))-(n1<<y)][(k|(1<<y))-(n2<<y)]+=dp[i][j][k];
				dp[i+1][(j|(1<<y))-(1<<y)][(k|(1<<y))-(1<<y)]+=dp[i][j][k]*25;
			}
			else{
				dp[i+1][(j|(1<<y))-(n1<<y)][(k|(1<<y))-(1<<y)]+=dp[i][j][k];
				dp[i+1][(j|(1<<y))-(1<<y)][(k|(1<<y))-(n2<<y)]+=dp[i][j][k];
				dp[i+1][(j|(1<<y))-(1<<y)][(k|(1<<y))-(1<<y)]+=dp[i][j][k]*24;
			}
		}
		rep(i,(1<<m)) rep(j,(1<<m)){
			if((i&(1<<(m-1))) && (j&(1<<(m-1)))) out=(out+dp[n*m][i][j])%mo;
		}
		return (int)out;
	}
};
