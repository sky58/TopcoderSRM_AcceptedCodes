//SRM386DIV1-500 PolygonCover

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;

double area(vector <int> x,vector <int> y){
	double ret=0.0;int n=x.size();
	for(int i=0;i<n;i++)
	ret+=0.5*(x[(i+1)%n]-x[i])*(y[(i+1)%n]+y[i]);
	return fabs(ret);
}

class PolygonCover{
	public:
	double PolygonCover::getArea(vector <int> x,vector <int> y){
		double dp[1<<16];double ar[20][20][20];int i,j,k,h,n=x.size();
		
		for(i=0;i<(1<<n);i++) dp[i]=10e10;dp[0]=0;
		for(i=0;i<n-2;i++) for(j=i+1;j<n-1;j++) for(k=j+1;k<n;k++){
			vector <int> vx,vy;
			vx.push_back(x[i]);vx.push_back(x[j]);vx.push_back(x[k]);
			vy.push_back(y[i]);vy.push_back(y[j]);vy.push_back(y[k]);
			ar[i][j][k]=area(vx,vy);
		}
		for(h=0;h<(1<<n);h++){
			for(i=0;i<n-2;i++) for(j=i+1;j<n-1;j++) for(k=j+1;k<n;k++){
				int t=(1<<i)+(1<<k)+(1<<j);t=t|h;
				dp[t]=min(dp[t],dp[h]+ar[i][j][k]);
			}
		}
		return dp[(1<<n)-1];
	}
};
