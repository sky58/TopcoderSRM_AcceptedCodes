//SRM454DIV1-250 DoubleXor
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
int ke(int a,int b){
	int out=0,t=1;
	while(a>0 || b>0){
		int a1=a%10,b1=b%10;
		out+=((a1|b1)-(a1&b1))%10*t;
		t*=10;a/=10;b/=10;
	}
	return out;
}
class DoubleXor{
	public:
	int DoubleXor::calculate(int n){
		int out=n,i;
		for(i=n-1;i>0;i--) out=ke(out,i);
		return out;
	}
};
