//SRM237DIV1-600 CakeDivision
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
double ch(double a){
	if(a<1.0) return 1.0/a;return a;
}
double cal(double a,int b){
	if(b<2) return a;int i;double ret=1e8;
	for(i=1;i+i<=b;i++){
		ret<?=max(cal(a/i*b,i),cal(a/(b-i)*b,b-i));
		ret<?=max(cal(ch(a/b*i),i),cal(ch(a/b*(b-i)),b-i));
	}
	return ret;
}
class CakeDivision{
	public:
	double CakeDivision::ratio(int w,int h,int n){
		return cal(ch(1.0*w/h),n);
	}
};
