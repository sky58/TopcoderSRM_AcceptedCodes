//SRM395DIV1-250 StreetWalking
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
class StreetWalking{
	public:
	long long StreetWalking::minTime(int x,int y,int a,int b){
		long long out=min((long long)a*(x+y),(long long)b*min(x,y)+(long long)a*(abs(x-y)));
		if((x+y)%2==0) out=min(out,(long long)b*max(x,y));else out=min(out,(long long)b*max(x,y)+a-b);
		return out;
	}
};
