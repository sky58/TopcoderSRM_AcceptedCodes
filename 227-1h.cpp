//SRM227DIV1-1000 QuadrilateralSearch
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
vector <lint> a;double pi=3.1415926535897932384626;
int bs(int lo,int hi,lint t){
	while(hi>lo){
		int mi=(lo+hi+1)/2;
		if(a[mi]>t) hi=mi-1;else lo=mi;
	}
	return hi;
}
double cal(double d,double n,double x,double y,double z){
	return d/2*d/2*0.5*(sin(pi*2.0*(y-x)/n)+sin(pi*2.0*(z-y)/n));
}
class QuadrilateralSearch{
	public:
	double QuadrilateralSearch::findLargest(int d,int n,int c,int g){
		int i,j;double out=0.0;
		for(i=0;i<c;i++){
			a.pb(((lint)i*g)%n);
		}
		sort(a.begin(),a.end());
		for(i=0;i<c;i++) a.pb(n+a[i]);
		for(i=0;i<c-2;i++) for(j=i+2;j<c;j++){
			if(i<1 && j>c-2) continue;
			int s=bs(i+1,j-1,(a[i]+a[j])/2),t=bs(j+1,i+c-1,(a[j]+a[i+c])/2);//cout<<a[i]<<' '<<a[j]<<' '<<a[s]<<' '<<a[t]<<endl;
			out>?=max(cal(d,n,a[i],a[s],a[j]),cal(d,n,a[i],a[s+1],a[j]))+max(cal(d,n,a[j],a[t],a[i+c]),cal(d,n,a[j],a[t+1],a[i+c]));
		}
		return out;
	}
};
