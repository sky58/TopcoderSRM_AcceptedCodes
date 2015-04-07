//SRM298DIV1-250 FibonacciPositioning
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
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
class FibonacciPositioning{
	public:
	double FibonacciPositioning::getFPosition(int A){
		lint a=A,b=1,c=1;if(a==1) return 2;
		for(int i=1;;i++){
			if(b>=a) return i+1.0*(a-c)/(b-c);lint d=b+c;c=b;b=d;
		}
	}
};
