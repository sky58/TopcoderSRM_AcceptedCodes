//SRM362DIV1-250 MaximizeSquares
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
class MaximizeSquares{
	public:
	int MaximizeSquares::squareCount(int a){
		if(a<4) return 0;
		int i,t,out=0;
		for(t=2;t<=1000;t++){
			if(a>=(t*t) && a<(t+1)*(t+1)) break;
		}
		if(t*t==a){
			for(i=1;i<t;i++) out+=(t-i)*(t-i);
			return out;
		}
		if(t*(t+1)==a){
			for(i=1;i<t;i++) out+=(t+1-i)*(t-i);
			return out;
		}
		if(t*(t+1)<a){
			int s=a-t*(t+1)-1;
			for(i=1;i<t;i++) out+=(t+1-i)*(t-i);
			for(i=1;i<=s;i++) out+=i;
			return out;
		}
		int s=a-1-t*t;
		for(i=1;i<t;i++) out+=(t-i)*(t-i);
		for(i=1;i<=s;i++) out+=i;
		return out;
	}
};
