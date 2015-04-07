//SRM323DIV1-500 Survived
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
class Survived{
	public:
	double Survived::minTime(int x,int y,int v,int u){
		double a=0.0,b=1e10;int i;if(x==0 && y==0) return 0.0;
		for(i=0;i<200;i++){
			double c=(a*2+b)/3,d=(a+b*2)/3;
			double s=sqrt(1.0*y*y+(x-u*c)*(x-u*c))/c,t=sqrt(1.0*y*y+(x-u*d)*(x-u*d))/d;
			if(s<t) b=d;else a=c;
		}
		double e=(a+b)/2,f=0.0;if(sqrt(1.0*y*y+(x-u*e)*(x-u*e))/e-1e-12>1.0*v) return -1.0;
//		cout<<e<<endl;
		for(i=0;i<100;i++){
			double g=(e+f)/2;
			if(sqrt(1.0*y*y+(x-u*g)*(x-u*g))/g<1.0*v) e=g;else f=g;
		}
		return (e+f)/2;
	}
};
