//SRM230DIV1-300 SortEstimate
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
class SortEstimate{
	public:
	double SortEstimate::howMany(int a,int b){
		double x=10e9,y=0,z,m=(double)b/a,k=log(2);
		for(int i=0;i<100;i++)
		{
			z=(x+y)/2;
			if(log(z)/k*z>m) x=z;else y=z;
		}
		return z;
	}
};
