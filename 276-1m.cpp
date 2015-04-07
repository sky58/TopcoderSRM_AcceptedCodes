//SRM276DIV1-500 TesingCar
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
double s[55],t[55],d[55];
double cal(double a,int b,int c){
//	if(t[b]>d[b]){
//		if(a>t[b]) return s[b];return (t[b]-a)*c+s[b];
//	}
	if(a<t[b]) return (t[b]-a)*c+s[b];
	if(a<d[b]) return s[b];return (a-d[b])*c+s[b];
}
class TestingCar{
	public:
	double TestingCar::maximalSpeed(vector <string> a,int b,int c){
		double out=0.0;vector <double> x;int i,n=a.size(),j,k;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>s[i]>>t[i]>>d[i];d[i]+=t[i];x.pb(t[i]);x.pb(d[i]);
		}
		x.pb(0);x.pb(b);sort(x.begin(),x.end());
		for(i=0;i<x.size()-1;i++){
			if(x[i]>=1.0*b) break;
			if(x[i]==x[i+1]) continue;
			double o=x[i],p=x[i+1],ret=1e10;
			for(j=0;j<200;j++){
				double q=(2*o+p)/3,r=(o+2*p)/3,y=q*c,z=r*c;
				for(k=0;k<n;k++){y<?=cal(q,k,c);z<?=cal(r,k,c);}
				if(y<z) o=q;else p=r;
			}
			ret<?=(o+p)/2*c;for(k=0;k<n;k++) ret<?=cal((o+p)/2,k,c);out>?=ret;
//			cout<<x[i]<<' '<<x[i+1]<<' '<<ret<<endl;
		}
		return out;
	}
};
