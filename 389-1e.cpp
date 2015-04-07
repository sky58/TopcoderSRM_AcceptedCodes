//SRM389DIV1-250 ApproximateDivision
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
class ApproximateDivision{
	public:
	double ApproximateDivision::quotient(int a,int b,int te){
		int i,t=1,c;double f,out=0.0;
		
		while(t<b) t*=2;c=t-b;f=1/(double)t;
		for(i=0;i<te;i++){
			out+=f;f*=c;f/=t;
		}
		return out*a;
	}
};
