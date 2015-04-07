//SRM417DIV1-1000 WalkingDistance
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
#include<queue>
#include<deque>
using namespace std;
class WalkingDistance{
	public:
	double WalkingDistance::getLongestShortest(vector <int> x,vector <int> y,vector <string> a){
		double out=0.0;int i,j,k,l,n=a.size();
		double flo[60][60];
		
		for(i=0;i<n;i++) for(j=0;j<n;j++) flo[i][j]=10e10;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(a[i][j]=='Y' || i==j) flo[i][j]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
		
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) flo[j][k]<?=flo[j][i]+flo[i][k];
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) for(k=0;k<n-1;k++) for(l=k+1;l<n;l++){
			if(a[i][j]=='N' || a[k][l]=='N') continue;
			out>?=(flo[i][j]+flo[k][l]+min(flo[i][k]+flo[j][l],flo[i][l]+flo[j][k]))*0.5;
		}
		return out;
	}
};
