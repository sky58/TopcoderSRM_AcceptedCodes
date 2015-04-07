//SRM266DIV1-450 ZCurve
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
class ZCurve{
	public:
	int ZCurve::zValue(int n,int r,int c){
		int out=0,i;
		for(i=n-1;i>=0;i--){
			if(r>=(1<<i)) out+=2*(1<<(i*2));if(c>=(1<<i)) out+=(1<<(i*2));
			r%=(1<<i);c%=(1<<i);
		}
		return out;
	}
};
