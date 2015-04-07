//SRM278DIV1-250 BestTriangulation
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
int x[55],y[55];
double area(vector <int> x,vector <int> y){
	double ret=0.0;int n=x.size();
	for(int i=0;i<n;i++)
	ret+=0.5*(x[(i+1)%n]-x[i])*(y[(i+1)%n]+y[i]);
	return fabs(ret);
}
class BestTriangulation{
	public:
	double BestTriangulation::maxArea(vector <string> a){
		int n=a.size(),i,j,k;double out=0.0;
		for(i=0;i<n;i++){istringstream sin(a[i]);sin>>x[i]>>y[i];}
		for(i=0;i<n-2;i++) for(j=i+1;j<n-1;j++) for(k=j+1;k<n;k++){
			vector <int> s,t;
			s.pb(x[i]);s.pb(x[j]);s.pb(x[k]);
			t.pb(y[i]);t.pb(y[j]);t.pb(y[k]);
			out>?=area(s,t);
		}
		return out;
	}
};
