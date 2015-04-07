//SRM390DIV1-500 PaintingBoards

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
vector <int> a,b;

bool kei(double c){
	vector <int> dp;int r[60][60];
	int n=a.size(),m=b.size(),i,j,k,s;
	for(i=0;i<(1<<m);i++) dp.push_back(0);
	
	for(i=0;i<m;i++) for(j=0;j<n;j++){
		s=0;
		for(k=j;k<n;k++){
			s+=a[k];if(s>b[i]*c) break;
		}
		r[i][j]=k;
	}
	for(i=0;i<m;i++) r[i][n]=n;
	for(i=0;i<(1<<m);i++) for(j=0;j<m;j++){
		if(i&(1<<j)) continue;
		dp[i+(1<<j)]=max(dp[i+(1<<j)],r[j][dp[i]]);
	}
	if(dp[(1<<m)-1]==n) return true;else return false;
}

class PaintingBoards{
	public:
	double PaintingBoards::minimalTime(vector <int> A,vector <int> B){
		double x=0.0,y=10e7,z;a=A;b=B;
		
		while(y-x>10e-10){
			z=(x+y)/2;if(kei(z)) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
