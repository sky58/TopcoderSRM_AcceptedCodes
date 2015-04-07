//SRM347DIV1-250 Aircraft
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
class Aircraft{
	public:
	string Aircraft::nearMiss(vector <int> a,vector <int> b,vector <int> c,vector <int> d,int r){
		double m=0,n=10e9;int i,j;
//		double t1=1,d1=0;
//		for(j=0;j<3;j++) d1+=(a[j]+b[j]*t1-c[j]-d[j]*t1)*(a[j]+b[j]*t1-c[j]-d[j]*t1);printf("%f\n",d1);
		for(i=0;i<100000;i++){
			double t1=(m*2+n)/3,t2=(m+n*2)/3;
			double d1=0,d2=0;
			for(j=0;j<3;j++){
				d1+=(a[j]+b[j]*t1-c[j]-d[j]*t1)*(a[j]+b[j]*t1-c[j]-d[j]*t1);
				d2+=(a[j]+b[j]*t2-c[j]-d[j]*t2)*(a[j]+b[j]*t2-c[j]-d[j]*t2);
			}
			d1=sqrt(d1);d2=sqrt(d2);
//			printf("%f %f %f %f\n",d1,d2,t1,t2);
			if(d1<=10e-12+r || d2<=10e-12+r) return "YES";
			if(d1>d2) m=t1;else n=t2;
		}
		return "NO";
	}
};
