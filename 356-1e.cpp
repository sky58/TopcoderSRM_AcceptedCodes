//SRM356DIV1-250 AverageProblem
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
class AverageProblem{
	public:
	int AverageProblem::numberOfParticipants(vector <string> a){
		vector <double> b;double c;int i,j;
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);
			while(sin>>c) b.pb(c);
		}
		for(i=1;i<1000;i++){
			int f=0;
			for(j=0;j<b.size();j++){
				double x=b[j]*i,y=(b[j]+0.001)*i;lint t;
//				if(1.0*(lint)x+1e-10>x) t=(lint)x;else t=(lint)x+1;
//				cout<<i<<' '<<t<<endl;
//				if(1.0*t+1e-10>y*i) f=1;
				if(1.0*(int)y+1e-10>y) t=(lint)y-1;else t=(lint)y;
				if(x-1e-10>1.0*t) f=1;
			}
			if(f==0) return i;
		}
		return 1000;
	}
};
