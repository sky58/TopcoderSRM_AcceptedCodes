//SRM257DIV1-300 Predicting
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
class Predicting{
	public:
	double Predicting::avgError(vector <double> a){
		int t,n=a.size();double i,j,k,l,m,out=1e10;
		for(i=-1.0;i<=1.0;i+=0.1) for(j=-1.0;j<=1.0;j+=0.1) for(k=-1.0;k<=1.0;k+=0.1) for(l=-1.0;l<=1.0;l+=0.1) for(m=-1.0;m<=1.0;m+=0.1){
			if(fabs(i+j+k+l+m-1.0)>1e-10) continue;
			double f=0.0;
			for(t=0;t<n-5;t++){
				f+=fabs((a[t]*i+a[t+1]*j+a[t+2]*k+a[t+3]*l+a[t+4]*m)-a[t+5]);
			}
			out<?=(f/(n-5));
//			if((f/(n-5))<=0.6) cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<endl;
		}
		return out;
	}
};
