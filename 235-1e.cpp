//SRM235DIV1-300 StepperMotor
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
class StepperMotor{
	public:
	int StepperMotor::rotateToNearest(int A,int B,vector <int> c){
		lint a=A,b=B,out=-a;int i,n=c.size();vector <lint> d;
		b%=a;if(b<0){b+=a;b%=a;}//cout<<a<<' '<<b<<endl;
		for(i=0;i<n;i++){d.pb(c[i]%a);if(d[i]<0){d[i]+=a;d[i]%=a;}}
		for(i=0;i<n;i++){
			lint t=(d[i]+a-b)%a;if(t>a/2) t=t-a;//cout<<d[i]<<' '<<t<<endl;
			if(abs(out)>abs(t) || (abs(out)==abs(t) && t>out)) out=t;
		}
		return out;
	}
};
