//SRM443DIV1-300 CirclesCountry
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
class CirclesCountry{
	public:
	int CirclesCountry::leastBorders(vector <int> x,vector <int> y,vector <int> r,int x1,int y1,int x2,int y2){
		int a[55];int i,out=0;
		memset(a,0,sizeof(a));
		for(i=0;i<x.size();i++){
			if((x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i])<r[i]*r[i]) a[i]++;
			if((x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i])<r[i]*r[i]) a[i]++;
		}
		for(i=0;i<x.size();i++) out+=a[i]%2;
		return out;
	}
};
