//SRM273DIV1-500 SnakeTurbo
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
double dp[55][55][55];
int a,b,n,s1=-1,s2=-1;vector <int> c;vector <double> zyo;
double rec(int x,int y,int z){
	if(x==y){
		if(x==s1 || x==s2) return dp[x][y][z]=1.0*abs(a-c[x]);
		else return dp[x][y][z]=1e12;
	}
	if(dp[x][y][z]>-0.5) return dp[x][y][z];
	if(y==z){
		return dp[x][y][z]=min(zyo[y-x]*abs(c[y]-c[x])+rec(x,y-1,x),zyo[y-x]*abs(c[y]-c[y-1])+rec(x,y-1,y-1));
	}
	return dp[x][y][z]=min(zyo[y-x]*abs(c[y]-c[x])+rec(x+1,y,y),zyo[y-x]*abs(c[x]-c[x+1])+rec(x+1,y,x+1));
}
class SnakeTurbo{
	public:
	double SnakeTurbo::finishTime(int A,int B,vector <int> C){
		c=C;a=A;b=B;n=c.size();sort(c.begin(),c.end());
		int i,j,k;double out=1.0*abs(a-b);
		if(n<1) return out;
		zyo.pb(1.0);for(i=0;i<60;i++) zyo.pb(0.5*zyo[i]);
		if(c[0]>a) s1=0;
		else if(c[n-1]<a) s1=n-1;
		else{for(i=0;i<n-1;i++){if(c[i]<a && c[i+1]>a){s1=i;s2=i+1;}}}
		for(i=0;i<55;i++) for(j=0;j<55;j++) for(k=0;k<55;k++) dp[i][j][k]=-1.0;
		for(i=0;i<n;i++) for(j=i;j<n;j++) out<?=min(rec(i,j,i)+zyo[j-i+1]*abs(b-c[i]),rec(i,j,j)+zyo[j-i+1]*abs(b-c[j]));
		return out;
	}
};
