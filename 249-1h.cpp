//SRM249DIV1-850 CultureGrowth
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
typedef pair<double,double> po;
double ga(po a,po b){return a.fi*b.se-a.se*b.fi;}
po pl(po a,po b){return mp(a.fi+b.fi,a.se+b.se);}
po mi(po a,po b){return mp(a.fi-b.fi,a.se-b.se);}
po mu(po a,double b){return mp(a.fi*b,a.se*b);}
double dist(po a,po b){return sqrt(1.0*(a.fi-b.fi)*(a.fi-b.fi)+1.0*(a.se-b.se)*(a.se-b.se));}
bool cross(po a1,po a2,po b1,po b2){
	return (ga(mi(a2,a1),mi(b1,a1))*ga(mi(a2,a1),mi(b2,a1))<1e-10) && 
		(ga(mi(b2,a1),mi(a1,b1))*ga(mi(b2,b1),mi(a2,b1))<1e-10);
}
double area(vector <po> a){
	double ret=0.0;
	for(int i=0;i<a.size()-1;i++) ret+=0.5*(a[i].se+a[i+1].se)*(a[i+1].fi-a[i].fi);
	return fabs(ret);
}
po crop(po a1,po a2,po b1,po b2){
	double d1=fabs(ga(mi(b2,b1),mi(a1,b1)));
	double d2=fabs(ga(mi(b2,b1),mi(a2,b1)));
	return pl(a1,mu(mi(a2,a1),d1/(d1+d2)));
}
vector <po> convexhull(vector <po> a){
	int n=a.size(),k=0,i;sort(a.begin(),a.end());
	po re[2*n];vector <po> ret;
	for(i=0;i<n;re[k++]=a[i++]){
		while(k>=2 && ga(mi(re[k-1],re[k-2]),mi(a[i],re[k-2]))<=0) k--;
	}
	int t=k+1;
	for(i=n-2;i>=0;re[k++]=a[i--]){
		while(k>=t && ga(mi(re[k-1],re[k-2]),mi(a[i],re[k-2]))<=0) k--;
	}
	for(i=0;i<k-1;i++) ret.pb(re[i]);ret.pb(ret[0]);
	return ret;
}
class CultureGrowth{
	public:
	double CultureGrowth::finalTray(vector <int> a,vector <int> b){
		int i,n=a.size();vector <po> c;for(i=0;i<n;i++) c.pb(mp(a[i],b[i]));
		if(n<3) return 0.0;return area(convexhull(c));
	}
};
