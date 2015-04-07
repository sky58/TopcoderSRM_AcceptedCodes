//SRM317DIV1-500 CollectingPayment
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
double dp[55][55];
int n,c;double d;vector <int> a,b;
double calc(int x,int y){
	if(dp[x][y]>-1e9) return dp[x][y];
	if(x==n) return 0.0;
	int kei=-c,i;
	for(i=y;i<=x;i++) kei+=a[i];
	return dp[x][y]=max(calc(x+1,y),calc(x+1,x+1)+pow(d,(365-b[x])/7+1)*kei);
}
class CollectingPayment{
	public:
	double CollectingPayment::maximumProfit(vector <int> A,vector <int> B,int C,int D){
		a=A;b=B;n=a.size();c=C;d=1.0+0.001*D;
		for(int i=0;i<55;i++) for(int j=0;j<55;j++) dp[i][j]=-1e10;
		return calc(0,0);
	}
};
