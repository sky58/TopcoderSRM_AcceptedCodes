//SRM286DIV1-600 BallGift
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
int no;double dp[20][20][20][35];
double rec(int g,int r,int b,int a){
	if(g+r+b<1){
		if(a==0) return dp[g][r][b][a]=1.0;return dp[g][r][b][a]=0.0;
	}
	if(dp[g][r][b][a]>-0.5) return dp[g][r][b][a];
	double ret=0.0;int p=no+b,ke=g+r+b;
	if(g>0) ret+=rec(g-1,r,b,(a+p-1)%p)*g/ke;
	if(r>0) ret+=rec(g,r-1,b,p-a-1)*r/ke;
	if(b>0 && a>0) ret+=rec(g,r,b-1,a-1)*b/ke;
//	cout<<g<<' '<<r<<
	return dp[g][r][b][a]=ret;
}
class BallGift{
	public:
	int BallGift::bestPosition(int p,int g,int r,int b){
		int i,j,k,l,mai=-1;double ma=-1.0;no=p-b;
		for(i=0;i<20;i++) for(j=0;j<20;j++) for(k=0;k<20;k++) for(l=0;l<35;l++) dp[i][j][k][l]=-1.0;
		for(i=0;i<p;i++){
//			cout<<i<<' '<<rec(g,r,b,i)<<endl;
			if(rec(g,r,b,i)>ma+1e-10){ma=rec(g,r,b,i);mai=i;}
		}
		return mai;
	}
};
