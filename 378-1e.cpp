//SRM378DIV1-250 TrueStatements
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
class TrueStatements{
	public:
	int TrueStatements::numberTrue(vector <int> a){
		vector <int> b;int i;
		for(i=0;i<=50;i++) b.push_back(0);
		for(i=0;i<a.size();i++) b[a[i]]++;
		for(i=50;i>=0;i--) if(b[i]==i) return i;
		return -1;
	}
};
