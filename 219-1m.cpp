//SRM219DIV1-500 TurntableService
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
int dp[(1<<15)+10][20];
bool ok[20][20];
int rot[20];
class TurntableService{
	public:
	int TurntableService::calculateTime(vector <string> a){
		int i,j,k,n=a.size(),inf=100000000,out=inf,x;
		memset(ok,false,sizeof(ok));memset(rot,0,sizeof(rot));
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			while(sin>>x) ok[i][x]=true;
		}
		for(i=0;i<(1<<15)+10;i++) for(j=0;j<20;j++) dp[i][j]=inf;dp[0][0]=0;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(ok[j][(j+i)%n]) rot[i]+=(1<<j);
		}
		for(i=0;i<(1<<n);i++) rep(j,n) rep(k,n){
			int t=0;if(j!=k) t=min((j+n-k)%n,(k+n-j)%n)+1;
			dp[i|rot[k]][k]<?=dp[i][j]+t+15;
		}
		rep(i,n) out<?=dp[(1<<n)-1][i];return out;
	}
};
