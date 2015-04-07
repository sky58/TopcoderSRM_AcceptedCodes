//SRM258DIV1-250 AutoLoan
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
class AutoLoan{
	public:
	double AutoLoan::interestRate(double a,double b,int c){
		double x=1e10,y=0.0;int i,j;
		for(i=0;i<100;i++){
			double z=(x+y)/2,pl=a;
			for(j=0;j<c;j++){
				pl=pl*(1.0+z/12.0)-b;
			}
			if(pl>0) x=z;else y=z;
		}
		return (x+y)*50.0;
	}
};
