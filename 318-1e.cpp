//SRM318DIV1-250 ReturnToHome
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
class ReturnToHome{
	public:
	double ReturnToHome::goHome(int x,int y,int d,int t){
		double di=sqrt(1.0*x*x+1.0*y*y),out=1e10;
		int s=(int)(di/d);
		out<?=(di-s*d)+s*t;
		out<?=(s*d+d-di)+(s+1)*t;
		out<?=di;
		if(s>0) out<?=(s+1)*t;
		if(s==0) out<?=2*t;
		return out;
	}
};
