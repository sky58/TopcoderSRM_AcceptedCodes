//SRM233DIV1-250 PipeCuts
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
class PipeCuts{
	public:
	double PipeCuts::probability(vector <int> a,int b){
		int i,j,out=0;
		sort(a.begin(),a.end());
		for(i=0;i<a.size()-1;i++) for(j=i+1;j<a.size();j++){
			int x=a[i],y=a[j];
			if(x>b || y-x>b || 100-y>b) out++;
		}
		int k=a.size()*(a.size()-1)/2;
		return (double)out/k;
	}
};
