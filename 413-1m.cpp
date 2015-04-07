//SRM413DIV1-500 InfiniteSequence2

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
vector <int> memo;
int p, q, x, y;

long long kei(long long k){
	if(k<=0) return 1;
	if(k<5000000) return (long long)memo[k];
	return kei(k/p-x)+kei(k/q-y);
}

class InfiniteSequence2{
	public:
	long long InfiniteSequence2::calc(long long k, int a, int b, int c, int d){
		int i;p=a;q=b;x=c;y=d;memo.push_back(1);
		for(i=1;i<5000000;i++) memo.push_back(memo[max(0,i/p-x)]+memo[max(0,i/q-y)]);
		return kei(k);
	}
};
