//SRM244DIV1-450 Polyline
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
double dist(double x,double y){
	return sqrt(x*x+y*y);
}
class Polyline{
	public:
	double Polyline::length(int a,int b,int x0,int y0,int x1,int y1){
		return dist(2*a-abs(x0-x1),2*b-abs(y0-y1));
	}
};
