//SRM268DIV1-250 Airways
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
double pi=3.14159265359;
class Airways{
	public:
	double Airways::distance(int n,int ea,int no){
		if(ea==0 && no==0) return 0.0;int i;
		double ra=atan2(1.0*no,1.0*ea),de=sqrt(1.0*ea*ea+1.0*no*no);
		if(ra<0.0) ra+=2*pi;
		for(i=0;i<n;i++){
			double r1=2*pi*i/n,r2=2*pi*(i+1)/n;
//			cout<<r1<<' '<<ra<<' '<<r2<<endl;
			if(fabs(r1-ra)<1e-11) return de;
			if(fabs(r2-ra)<1e-11) return de;
			if(r1<ra && r2>ra){
				double t1=tan(ra-r1),t2=tan(r2-ra),h=de/(1.0/t1+1.0/t2);
//				cout<<ra-r1<<' '<<r2-ra<<' '<<h<<endl;
				return h/sin(ra-r1)+h/sin(r2-ra);
			}
		}
		return 0.0;
	}
};
