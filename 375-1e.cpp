//SRM375DIV1-250(DIV2-950) DivisibleByDigits
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
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class DivisibleByDigits{
	public:
	long long DivisibleByDigits::getContinuation(int n){
		long long k=n;vector <int> a;int b=1,t=1,i;
		
		while(n>0){
			if(n%10>1) a.push_back(n%10);
			n/=10;
		}
		for(i=0;i<a.size();i++) b=b*a[i]/gcd(b,a[i]);
		if(k%b==0) return k;
		while(1){
			t*=10;if((k*t)%b==0) return k*t;
			long long x=b-(k*t)%b;
			if(x<t) return k*t+x;
		}
	}
};
