//SRM245DIV1-500 BikeLock
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
int dp[55][12][12][12];
int d[10]={0,1,1,1,2,2,2,1,1,1};
string a,b;
int ca(int c){
	return ((b[c]-'0')-(a[c]-'0')+100)%10;
}
class BikeLock{
	public:
	int BikeLock::minTurns(string A,string B){
		a=A;b=B;int i,j,k,l,n=a.size(),inf=1000000,m,o,p;a+="000";b+="000";
		for(i=0;i<55;i++) for(j=0;j<12;j++) for(k=0;k<12;k++) for(l=0;l<12;l++) dp[i][j][k][l]=inf;
		dp[0][ca(0)][ca(1)][ca(2)]=0;
		for(i=0;i<n;i++) for(j=0;j<10;j++) for(k=0;k<10;k++) for(l=0;l<10;l++){
			for(m=0;m<10;m++) for(o=0;o<10;o++){
				p=(100+j-m-o)%10;
				dp[i+1][(100+k-m-o)%10][(100+l-m)%10][ca(i+3)]<?=dp[i][j][k][l]+d[o]+d[m]+d[p];
			}
		}
		return dp[n][0][0][0];
	}
};
