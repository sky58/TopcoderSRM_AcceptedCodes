//SRM406DIV1-250 SymmetricPie
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
#define All(s) s.begin(),s.end()

int kei(vector <int> a){
	int i,j,ret=0,t;
	for(i=0;i<a.size();i++){
		t=0;
		for(j=i+a.size();j>=0;j--){
			t+=a[j%a.size()];if(t==50) ret++;
		}
	}
	return ret;
}

class SymmetricPie{
	public:
	int SymmetricPie::getLines(vector <int> a){
		int out=0;
		sort(All(a));
		do{
			out=max(out,kei(a));
		}while(next_permutation(All(a)));
		return out/2;
	}
};
