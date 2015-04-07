//SRM341DIV1-250 KLastNonZeroDigits
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
class KLastNonZeroDigits{
	public:
	string KLastNonZeroDigits::getKDigits(int a,int b){
		long long t=1;int i;string out;
		
		for(i=1;i<=a;i++) t*=i;
		while(t%10==0) t/=10;
		while(t>0 && b){
			out+=((t%10)+'0');t/=10;b--;
		}
		reverse(out.begin(),out.end());
		return out;
	}
};
