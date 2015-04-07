//SRM377DIV1-250 SquaresInsideLattice
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
class SquaresInsideLattice{
	public:
	long long SquaresInsideLattice::howMany(int a,int b){
		long long out=0;int i;
		for(i=1;i<100002;i++){
			if(i>a || i>b) break;
			out+=(long long)(a-i+1)*(b-i+1)*i;
		}
		return out;
	}
};
