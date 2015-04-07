//SRM310DIV1-900 BoxTower
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
int dp[33000][50];
bool oke[50][50];
class BoxTower{
	public:
	int BoxTower::tallestTower(vector <int> x,vector <int> y,vector <int> z){
		vector <vector <int> > bo;bo.pb(x);bo.pb(y);bo.pb(z);
		int i,j,k,l,m,n=x.size(),out=0;
		memset(oke,false,sizeof(oke));memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++) for(j=0;j<3;j++) for(k=0;k<n;k++) for(l=0;l<3;l++){
			vector <int> a,b;
			for(m=0;m<3;m++){
				if(m!=j) a.pb(bo[m][i]);if(m!=l) b.pb(bo[m][k]);
			}
			if(b[0]<=a[0] && b[1]<=a[1]) oke[i*3+j][k*3+l]=true;
			if(b[1]<=a[0] && b[0]<=a[1]) oke[i*3+j][k*3+l]=true;
		}
		for(i=0;i<n;i++) for(j=0;j<3;j++) dp[1<<i][i*3+j]>?=bo[j][i];
		for(i=1;i<(1<<n);i++) for(j=0;j<n*3;j++) for(k=0;k<n;k++) for(l=0;l<3;l++){
			if(i&(1<<k)) continue;
			if(oke[j][k*3+l]) dp[i+(1<<k)][k*3+l]>?=dp[i][j]+bo[l][k];
		}
		for(i=0;i<(1<<n);i++) for(j=0;j<n*3;j++) out>?=dp[i][j];
		return out;
	}
};
