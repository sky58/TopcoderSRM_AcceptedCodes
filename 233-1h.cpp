//SRM233DIV1-1000 DistCut
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
class DiskCut{
	public:
	double DiskCut::minCost(int a,vector <int> b){
		int t,out=100;
		while(1){
			if(b.size()==1) break;
			sort(b.begin(),b.end());
			t=b[0]+b[1];out+=t;b[1]=t;b.erase(b.begin());
		}
		return out*a*0.01;
	}
};
