//SRM267DIV1-1000 HairCuts
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
int n;vector <double> c;double d;
int de(string a){
	int ret=(a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');
	if(ret<480) ret+=720;return ret;
}
bool ch(double t){
	double now=0.0;
	for(int i=0;i<n;i++) now=max(now,c[i])+t;
	if(now<=d+1e-10) return true;return false;
}
class HairCuts{
	public:
	double HairCuts::maxCut(vector <string> a,string b){
		n=a.size();int i;for(i=0;i<n;i++) c.pb(1.0*de(a[i]));d=1.0*de(b);
		sort(c.begin(),c.end());double x=5.0,y=1e10;
		if(!ch(5.0)) return -1.0;
		for(i=0;i<100;i++){
			double z=(x+y)/2;if(ch(z)) x=z;else y=z;
		}
		return (x+y)/2;
	}
};
