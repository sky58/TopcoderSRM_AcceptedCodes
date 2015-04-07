//SRM346DIV1-250 CommonMultiples
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
long long gcd( long long m, long long n )
{
	long long a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
class CommonMultiples{
	public:
	int CommonMultiples::countCommMult(vector <int> a,int b,int c){
		long long k=1;int i;
		for(i=0;i<a.size();i++){
			k=k/gcd((long long)a[i],k)*a[i];
			if(k>2000000000) return 0;
		}
		int out=(int)((long long)c/k);
		out-=(int)((long long)(b-1)/k);
		return out;
	}
};
