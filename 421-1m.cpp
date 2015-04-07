//SRM421DIV1-500 CakesEqualization

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
class CakesEqualization{
	public:
	double CakesEqualization::fairDivision(std::vector <int> x, int k){
		int i, j, n=x.size(), f;int t[50];
		double out=1000000000.0, ma, mi;
		for(i=0;i<n;i++) t[i]=1;
		for(i=0;i<=k;i++){
			ma=0.0;mi=1000000000.0;
			for(j=0;j<n;j++){
				ma=max(ma,x[j]/(double)t[j]);mi=min(mi,x[j]/(double)t[j]);
			}
			out=min(out,(ma-mi));
			ma=0.0;
			for(j=0;j<n;j++){
				if(ma<x[j]/(double)t[j]){
					f=j;ma=x[j]/(double)t[j];
				}
			}
			t[f]++;
		}
		return out;
	}
};
