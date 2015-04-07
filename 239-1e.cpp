//SRM239DIV1-250 ATaleOfThreeCities
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
double dist(double a,double b,double c,double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
class ATaleOfThreeCities{
	public:
	double ATaleOfThreeCities::connect(vector <int> ax,vector <int> ay,vector <int> bx,vector <int> by,vector <int> cx,vector <int> cy){
		int a=ax.size(),b=bx.size(),c=cx.size(),i,j;double x=1e8,y=1e8,z=1e8;
		for(i=0;i<a;i++) for(j=0;j<b;j++) x<?=dist(ax[i],ay[i],bx[j],by[j]);
		for(i=0;i<a;i++) for(j=0;j<c;j++) y<?=dist(ax[i],ay[i],cx[j],cy[j]);
		for(i=0;i<c;i++) for(j=0;j<b;j++) z<?=dist(cx[i],cy[i],bx[j],by[j]);
//		cout<<x<<' '<<y<<' '<<z<<endl;
		double out=x+y;out<?=x+z;out<?=y+z;return out;
	}
};
