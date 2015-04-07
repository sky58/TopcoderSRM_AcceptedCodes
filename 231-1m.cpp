//SRM231DIV1-450 LargeSignTest

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
class LargeSignTest{
	public:
	string LargeSignTest::pvalue(int a,int b){
		int i,c=min(b,a-b),n=a-1;
		if(c*2==a) return "100.0%";
		double x=1.0,y=1.0;
		for(i=1;i<=c;i++){
			x*=(a-i+1);x/=i;y+=x;
			while((x>2 || y>2) && n>0){x/=2;y/=2;n--;}
		}
		for(i=0;i<n;i++) y/=2;
		y*=1000;y+=0.5;int ret=(int)y;
		stringstream out;
		out<<ret/10<<'.'<<ret%10<<'%';
		return out.str();
	}
};
