//SRM235DIV1-900 RemoteRover
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
class RemoteRover{
	public:
	double RemoteRover::optimalTravel(vector <int> w,vector <int> s,int o){
		int i,n=w.size(),j;
		double hi=1.0-1e-8,lo=0.0,out=0.0;
		for(i=0;i<10000;i++){
			double mi=(hi+lo)/2,now=mi,sum=0.0;
			for(j=0;j<n;j++){
				sum+=w[j]*now/sqrt(1-now*now);if(j<n-1) now*=1.0*s[j+1]/s[j];
			}
			if(sum<1.0*o) lo=mi;else hi=mi;
		}
		for(j=0;j<n;j++){
			out+=w[j]/sqrt(1-hi*hi)/s[j];if(j<n-1) hi*=1.0*s[j+1]/s[j];
		}
		return out;
	}
};
