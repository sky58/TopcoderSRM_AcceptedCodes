//SRM403DIV1-250 TheLuckyNumbers
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

class TheLuckyNumbers{
	public:
	int TheLuckyNumbers::count(int a, int b){
		vector <vector <int> > e;vector <int> ee;int i,j,t=1,out=0;
		ee.push_back(4);ee.push_back(7);e.push_back(ee);
		for(i=0;i<8;i++){
			t*=10;vector <int> c;
			for(j=0;j<e[i].size();j++){c.push_back(4*t+e[i][j]);c.push_back(7*t+e[i][j]);}
			e.push_back(c);
		}
		for(i=0;i<e.size();i++) for(j=0;j<e[i].size();j++) if(e[i][j]<=b && e[i][j]>=a) out++;
		return out;
	}
};
