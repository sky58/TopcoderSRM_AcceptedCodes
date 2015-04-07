//SRM409DIV1-900 GridColoring

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
int K, W, H, B;
long double kei(int a, int b){
	long double p;long long s;
	s=(long long)(a+1)*(b+1)*(W-b)*(H-a)*2-1;
	s+=(long long)((a+1)*(H-a)-1)*((b+1)*(W-b)-1)*2;
	p=s/(long double)B/B;
	return 1.0-pow(1.0-p,K);
}

class GridColoring{
	public:
	double GridColoring::area(int k, int w, int h){
		int i, j;long double out=0.0;
		K=k;H=h;W=w;B=h*w;
		for(i=0;i<h;i++) for(j=0;j<w;j++) out+=kei(i, j);
		return (double)out;
	}
};
