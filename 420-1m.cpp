//SRM420DIV1-500 RedIsGood

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

class RedIsGood{
	public:
	double RedIsGood::getProfit(int r, int b){
		vector <double> t;vector <double> tt;vector <double> f;
		int i, j;
		for(i=0;i<=b;i++) t.push_back(0.0);
		for(i=1;i<=r;i++){
			tt.push_back((double)i);
			for(j=1;j<=b;j++) tt.push_back(max(0.0,(i*(1.0+t[j])+j*(-1.0+tt[j-1]))/(i+j)));
			t=tt;tt=f;
		}
		return t[b];
	}
};
