//SRM238DIV1-1000 SquareLanguage
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
class SquareLanguage{
	public:
	long long SquareLanguage::howMany(vector <int> a,vector <int> b,vector <int> c,vector <int> d){
		int i,j,t=-1;
		lint out=1LL*(a[1]-a[0]+1)*(b[1]-b[0]+1)*(c[1]-c[0]+1)*(d[1]-d[0]+1);out*=out;
		vector <vector <int> > e;
		e.pb(a);e.pb(b);e.pb(c);e.pb(d);
		for(i=0;i<4;i++){
			if(e[i][0]>0){if(t<0) t=i;else return out;}
		}
		for(i=0;i<4;i++){
			if(t>=0 && i!=t) continue;lint f=1;
			for(j=0;j<4;j++){
				if(i!=j) f*=(e[j][1]-e[j][0]+1);else f*=(e[j][1]-e[j][0])*(e[j][1]-e[j][0]);
			}
			out-=f;
		}
		return out;
	}
};
