//SRM407DIV1-500 PointsGame

#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;
double memo[1000000];
int N;vector <int> x,y,z;

double ten(int a){
	vector <int> s,g;
	int i,j;double ret=0.0;
	for(i=0;i<N;i++){
		if(a%3==1) s.push_back(i);else g.push_back(i);a/=3;
	}
	for(i=0;i<s.size();i++) for(j=0;j<g.size();j++) ret+=sqrt((double)(x[s[i]]-x[g[j]])*(x[s[i]]-x[g[j]])+(y[s[i]]-y[g[j]])*(y[s[i]]-y[g[j]]));
	return ret;
}

double kei(int a,int b){
	double ret=0.0;int i;
	if(memo[a]>-1) return memo[a];
	if(b==N) return ten(a);if(b%2==1) ret=10e10;
	if(b%2==0) for(i=0;i<N;i++) if(a/z[i]%3==0) ret=max(ret,kei(a+z[i],b+1));
	if(b%2==1) for(i=0;i<N;i++) if(a/z[i]%3==0) ret=min(ret,kei(a+z[i]*2,b+1));
	return memo[a]=ret;
}

class PointsGame{
	public:
	double PointsGame::gameValue(vector <int> px,vector <int> py){
		int i;
		N=px.size();x=px;y=py;z.push_back(1);
		for(i=1;i<13;i++) z.push_back(z[i-1]*3);
		for(i=0;i<1000000;i++) memo[i]=-1.0;
		return kei(0,0);
	}
};
