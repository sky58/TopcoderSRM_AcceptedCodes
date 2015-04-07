//SRM379DIV1-250 SellingProducts
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
class SellingProducts{
	public:
	int SellingProducts::optimalPrice(vector <int> a,vector <int> b){
		int out=0,ret=0,i,j;
		for(i=0;i<a.size();i++){
			int t=0,x=a[i];
			for(j=0;j<a.size();j++){
				if(a[j]<x) continue;
				t+=max(0,x-b[j]);
			}
			if(t>ret || (ret==t && out>x)){ret=t;out=x;}
		}
		if(ret==0) return 0;
		return out;
	}
};
