//SRM349DIV1-250 RaderFinder
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
class RadarFinder{
	public:
	int RadarFinder::possibleLocations(int x1,int y1,int r1,int x2,int y2,int r2){
		if(x1==x2 && y1==y2 && r1==r2) return -1;
		long long a,b,c;
		a=(long long)(x1-x2)*(x1-x2)+(long long)(y1-y2)*(y1-y2);
		b=(long long)(r1+r2)*(r1+r2);
		c=(long long)(r1-r2)*(r1-r2);
		if(a>b || a<c) return 0;if(a==b || a==c) return 1;return 2;
	}
};
