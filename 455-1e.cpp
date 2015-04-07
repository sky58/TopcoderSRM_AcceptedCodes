//SRM455DIV1-300 DonutsOnTheGridEasy
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
bool ta[55][55][55],yo[55][55][55];
int dp[55][55][55][55];
int rec(int x1,int y1,int x2,int y2){
	if(x1>=x2-1 || y1>=y2-1) return 0;
	if(dp[x1][y1][x2][y2]>-1) return dp[x1][y1][x2][y2];
	int ret=0;
	if(yo[x1][y1][y2] && yo[x2][y1][y2] && ta[y1][x1][x2] && ta[y2][x1][x2]) ret>?=1+rec(x1+1,y1+1,x2-1,y2-1);
	ret>?=rec(x1+1,y1,x2,y2);
	ret>?=rec(x1,y1+1,x2,y2);
	ret>?=rec(x1,y1,x2-1,y2);
	ret>?=rec(x1,y1,x2,y2-1);
	return dp[x1][y1][x2][y2]=ret;
}
class DonutsOnTheGridEasy{
	public:
	int DonutsOnTheGridEasy::calc(vector <string> a){
		int n=a.size(),m=a[0].size(),i,j,k,l;
		memset(ta,false,sizeof(ta));memset(yo,false,sizeof(yo));
		for(i=0;i<55;i++) for(j=0;j<55;j++) for(k=0;k<55;k++) for(l=0;l<55;l++) dp[i][j][k][l]=-1;
		for(i=0;i<n;i++) for(j=0;j<m-1;j++){
			if(a[i][j]=='.') continue;
			for(k=j+1;k<m;k++){
				if(a[i][k]=='.') break;yo[i][j][k]=true;
			}
		}
		for(i=0;i<m;i++) for(j=0;j<n-1;j++){
			if(a[j][i]=='.') continue;
			for(k=j+1;k<n;k++){
				if(a[k][i]=='.') break;ta[i][j][k]=true;
			}
		}
		return rec(0,0,n-1,m-1);
	}
};
