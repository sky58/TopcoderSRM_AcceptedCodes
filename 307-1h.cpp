//SRM307DIV1-1000 SplitAndMergeGame
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
int dp[1050][1050];
int n,m;
int ka0[1050],ka1[1050];
vector <int> a,b;
int rec(int x,int y){
	if(dp[x][y]>-1) return dp[x][y];
	if(x==(1<<n)-1 && y==(1<<m)-1) return 0;
	int ret=10000,st=ka0[x]-ka1[y],i,j,s;
	if(st>0) s=1;else s=0;
	for(i=0;i<n;i++){
		if(x&(1<<i)) continue;ret<?=rec(x+(1<<i),y)+s;
	}
	for(j=0;j<m;j++){
		if(y&(1<<j)) continue;
		if(st==b[j]) ret<?=rec(x,y+(1<<j));if(st>b[j]) ret<?=rec(x,y+(1<<j))+1;
	}
	for(i=0;i<n;i++){
		if(x&(1<<i)) continue;
		for(j=0;j<m;j++){
			if(y&(1<<j)) continue;
			if(a[i]==b[j]) ret<?=rec(x+(1<<i),y+(1<<j));
			else if(a[i]>b[j]) ret<?=rec(x+(1<<i),y+(1<<j))+1+s;
			else if(a[i]+st==b[j]) ret<?=rec(x+(1<<i),y+(1<<j))+1;
			else if(a[i]+st>b[j]) ret<?=rec(x+(1<<i),y+(1<<j))+2;
		}
	}
//	cout<<x<<' '<<y<<' '<<ret<<endl;
	return dp[x][y]=ret;
}
class SplitAndMergeGame{
	public:
	int SplitAndMergeGame::minMoves(vector <int> A,vector <int> B){
		int i,j;
		a=A;b=B;n=a.size();m=b.size();memset(ka0,0,sizeof(ka0));memset(ka1,0,sizeof(ka1));
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){if(i&(1<<j)) ka0[i]+=a[j];}
		for(i=0;i<(1<<m);i++) for(j=0;j<m;j++){if(i&(1<<j)) ka1[i]+=b[j];}
		if(ka0[(1<<n)-1]!=ka1[(1<<m)-1]) return -1;
		for(i=0;i<1050;i++) for(j=0;j<1050;j++) dp[i][j]=-1;
		return rec(0,0);
	}
};
