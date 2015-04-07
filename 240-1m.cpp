//SRM240DIV1-600 WatchTower
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
vector <double> x,y;int n;
double ca2(double a,int i){return y[i]+(y[i+1]-y[i])*(a-x[i])/(x[i+1]-x[i]);}
double ca(double a){double ret=0.0;int i;for(i=0;i<n-1;i++) ret>?=ca2(a,i);return ret;}
class WatchTower{
	public:
	double WatchTower::minHeight(vector <int> X,vector <int> Y){
		int i,j;double out=1e13;
		n=X.size();for(i=0;i<n;i++){x.pb(X[i]+0.0);y.pb(Y[i]+0.0);}
		for(i=0;i<n-1;i++){
			double a=x[i],b=x[i+1];
			for(j=0;j<200;j++){
				double c=(a*2+b)/3,d=(a+b*2)/3;
				if(ca(c)-ca2(c,i)>ca(d)-ca2(d,i)) a=c;else b=d;
			}
			out<?=ca(a)-ca2(a,i);
		}
		return out;
	}
};
