//SRM310DIV1-250 PyramidOfCubes
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int ca1(int a,int i){
	return (a-1)/i+1;
}
int ca2(int a,int i){
	if(a<i) return a;return i;
}
double calc(int a,int t){
	int i;lint k=0;
	if(a<t*t){
		return 2.0*a+2.0*ca1(a,t)+2.0*ca2(a,t);
	}
	for(i=t;i>0;i--){
		if(a<=i*i){
			return 4.0*k+2.0*ca1(a,i)+2.0*ca2(a,i)+2.0*t*t;
		}
		a-=i*i;k+=i;
	}
};
class PyramidOfCubes{
	public:
	double PyramidOfCubes::surface(int a){
		int i,t=0;
		for(i=1;i<32000;i++){
			t+=i*i;if(a<=t) return calc(a,i);
		}
	}
};
