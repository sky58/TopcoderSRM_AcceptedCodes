//SRM443-DIV1-600 BinaryFlips
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
typedef long long lint;
class BinaryFlips{
	public:
	int BinaryFlips::minimalMoves(int a,int b,int c){
		if(a==0) return 0;
		if(a%c==0) return a/c;
		if(a%2==1 && c%2==0) return -1;
		if(a+b<=c) return -1;
		for(int i=1;i<210000;i++){
			lint kei=i,a2=a,d=a+b,syo,mo,ma;
			kei*=c;if(kei<a2) continue;
			kei-=a2;if(kei%2==1) continue;
			kei/=2;syo=kei/d;mo=kei%d;
			if(mo==0) ma=syo*2+1;
			else if(mo<=(lint)b) ma=syo*2+2;
			else ma=syo*2+3;
			if(ma<=(lint)i) return i;
		}
		return -1;
	}
};
