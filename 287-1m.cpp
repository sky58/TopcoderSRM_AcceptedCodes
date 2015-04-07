//SRM287DIV1-450 MooresLaw
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
class MooresLaw{
	public:
	double MooresLaw::shortestComputationTime(int a){
		double x=0.0,y=1.0*a,b=y;
		for(int i=0;i<500;i++){
			double z=(x*2+y)/3,w=(x+y*2)/3,s=z+b*pow(0.5,z/1.5),t=w+b*pow(0.5,w/1.5);
			if(s>t) x=z;else y=w;
		}
		return x+b*pow(0.5,x/1.5);
	}
};
