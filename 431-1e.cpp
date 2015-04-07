//SRM431DIV1-250 LasterShooting
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

class LaserShooting{
	public:
	double LaserShooting::numberOfHits(vector <int> x, vector <int> y1, vector <int> y2){
		double out=0.0;int i;
		for(i=0;i<x.size();i++) out+=fabs(atan2(y1[i],x[i])-atan2(y2[i],x[i]));
		return out/(3.14159265358979);
	}
};
