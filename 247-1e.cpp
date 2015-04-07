//SRM247DIV1-300 Musical
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
double mo(double a){
	return a-10*(int)(a/10);
}
class Musical{
	public:
	string Musical::loser(int n,double a){
		string out="";double ma=-1.0;int i,j;
		for(i=0;i<n;i++){
			double t=mo(10.0-10.0/n*i+a),mi=1e10;
			for(j=0;j<n;j++) mi<?=fabs(t-10.0/(n-1)*j);
//			cout<<mi<<endl;
			if(ma<mi){out=('A'+i);ma=mi;}
		}
		return out;
	}
};
