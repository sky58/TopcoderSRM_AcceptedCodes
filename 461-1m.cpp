//SRM461DIV1-500 BuildingCities
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
double dp[3000][55];
double flo[55][55],dist[55][55];
class BuildingCities{
	public:
	int BuildingCities::findMinimumCities(int a,int b,vector <int> x,vector <int> y){
		int i,j,k,n=x.size();
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			dist[i][j]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			if(dist[i][j]<=1.0*a) flo[i][j]=dist[i][j];else flo[i][j]=1e10;
		}
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) flo[j][k]<?=flo[j][i]+flo[i][k];
		for(i=0;i<3000;i++) for(j=0;j<55;j++) dp[i][j]=1e10;dp[0][0]=0.0;
		for(i=0;i<3000;i++){
			for(j=0;j<n;j++) for(k=0;k<n;k++) dp[i][k]<?=dp[i][j]+flo[j][k];
			for(j=0;j<n;j++) for(k=0;k<n;k++){
				int c=(int)(dist[j][k]-1e-9)/a;
				if(c+i<3000) dp[c+i][k]<?=dp[i][j]+dist[j][k];
			}
		}
		for(i=0;i<3000;i++){
			if(dp[i][n-1]<1.0*b) return i;
		}
		return -1;
	}
};
