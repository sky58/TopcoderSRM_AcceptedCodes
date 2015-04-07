//SRM445DIV1-275 TheHouseDivOne
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
#define pb push_back
class TheNewHouseDivOne{
	public:
	double TheNewHouseDivOne::distance(vector <int> x,vector <int> y,int k){
		int i,n=x.size();double a,b,out=300.0;
		for(a=-50.0;a<=50.0;a+=0.5) for(b=-50.0;b<=50.0;b+=0.5){
			vector <double> c;
			for(i=0;i<n;i++){
				c.pb(fabs((double)x[i]-a)+fabs((double)y[i]-b));
			}
			sort(c.begin(),c.end());out<?=c[k-1];
		}
		return out;
	}
};
