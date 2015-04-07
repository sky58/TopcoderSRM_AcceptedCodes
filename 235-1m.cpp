//SRM235DIV1-400 PerforatedSheet
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
class PerforatedSheet{
	public:
	vector <double> PerforatedSheet::getCenterOfMass(int w,int h,vector <int> x,vector <int> y,vector <int> a,vector <int> b){
//		long double cx=0.5*w,cy=0.5*h,si=1.0*w*h;
		int i,n=a.size();lint area=(lint)w*h,cx=area*w,cy=area*h;vector <double> out;
		for(i=0;i<n;i++){
			lint ar=(lint)a[i]*b[i];area-=ar;cx-=ar*(x[i]*2+a[i]);cy-=ar*(y[i]*2+b[i]);
		}
		if(area>0){out.pb(0.5*cx/area);out.pb(0.5*cy/area);}
		return out;
	}
};
