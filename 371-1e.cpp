//SRM371DIV1-250(DIV2-500) SpiralRoute
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
#include<queue>
#include<deque>
using namespace std;
class SpiralRoute{
	public:
	vector <int> SpiralRoute::thronePosition(int a,int b){
		int hx=a-1,hy=b-1,lx=0,ly=0,x=0,y=0,si=a*b-1;
		while(1){
			if(si<=0) break;si-=(hx-x);x=hx;ly++;
			if(si<=0) break;si-=(hy-y);y=hy;hx--;
			if(si<=0) break;si-=(x-lx);x=lx;hy--;
			if(si<=0) break;si-=(y-ly);y=ly;lx++;
		}
		vector <int> out;out.push_back(x);out.push_back(y);return out;
	}
};
