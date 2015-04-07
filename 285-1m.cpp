//SRM285DIV1-500 RobotTesting
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
int n;string b;double dp[1100][1100];
double cal(int nx,int ny){
	if(dp[nx][ny]>-0.5) return dp[nx][ny];
	int x=nx,y=ny,i;
	for(i=0;i<b.size();i++){
		if(b[i]=='U') x++;
		if(b[i]=='D') x--;
		if(b[i]=='L') y++;
		if(b[i]=='R') y--;
		if(x<0 || x>=n || y<0 || y>=n) return dp[nx][ny]=1.0+i;
	}
	if(nx==x && ny==y) return dp[nx][ny]=50000.0;
	return dp[nx][ny]=cal(x,y)+b.size();
}
class RobotTesting{
	public:
	double RobotTesting::estimateCommands(int N,string B){
		double out=0.0;int i,j;n=N;b=B;
		for(i=0;i<1100;i++) for(j=0;j<1100;j++) dp[i][j]=-1.0;
		for(i=0;i<n;i++) for(j=0;j<n;j++) out+=cal(i,j);
		return out/(n*n);
	}
};
