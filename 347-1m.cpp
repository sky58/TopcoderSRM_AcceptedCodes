//SRM347DIV1-450 FlightScheduler
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
int a,b,c,d;
double kei(int n){
	double kyo=(double)a/n;
	double ret=exp(kyo/b)-1.0;ret*=c;ret+=d;return ret*n;
}
class FlightScheduler{
	public:
	double FlightScheduler::minimizeFuel(int A,int B,int C,int D){
		a=A;b=B;c=C;d=D;int x=1,y=1000000000;
		while(1){
			if(y-x==2) break;
			int m=(x*2+y)/3,n=(x+y*2)/3;
			double d1=kei(m),d2=kei(n);
			if(d1>d2) x=m;else y=n;
		}
		double out=min(kei(x),kei(x+1));
		return min(out,kei(y));
	}
};
