//SRM405DIV1-1000 ReasonableOdds
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
int con[7][7];
int k;
double kei(double a,double b){
	int i,j;double ret=0.0;
	for(i=1;i<=k;i++) for(j=0;j<i;j++) 
	 ret+=pow(a,i)*pow(b,j)*pow(1.0-a,k-i)*pow(1.0-b,k-j)*con[k][i]*con[k][j];
	return ret;
}
double bs(double x,double y,double a,int b){
	double m=x,n=y;
	while(n>m+10e-12){
		double t=(m+n)*0.5;
		if(kei(t,a)>0.01*b) n=t;else m=t;
	}
	return (m+n)*0.5;
}
class ReasonableOdds{
	public:
	string ReasonableOdds::check(int p1,int pd,int p2,int K){
		k=K;int i,j;double x=0.0,y=0.0;
		if(pd==0){if(p1==0 || p2==0) return "YES";return "NO";}
		
		memset(con,0,sizeof(con));con[0][0]=1;
		for(i=0;i<6;i++) for(j=0;j<6;j++){
			con[i+1][j+1]+=con[i][j];con[i+1][j]+=con[i][j];
//			printf("%d %d %d\n",i,j,con[i][j]);
		}
		for(i=0;i<50000;i++){
			x=bs(x,1.0,y,p1);y=bs(y,1.0,x,p2);
//			printf("%f %f\n",x,y);
			if(x>1.0-10e-12 || y>1.0-10e-12) return "NO";
		}
		return "YES";
	}
};
