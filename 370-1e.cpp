//SRM370DIV1-250(DIV2-500) DrawingMarbles
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
class DrawingMarbles{
	public:
	double DrawingMarbles::sameColor(vector <int> a,int k){
		double out=0.0;int t=0,i,j;
		for(i=0;i<a.size();i++) t+=a[i];
		for(i=0;i<a.size();i++){
			if(a[i]<k) continue;double f=1.0;
			for(j=0;j<k;j++) f=f*(a[i]-j)/(t-j);
			out+=f;
		}
		return out;
	}
};
