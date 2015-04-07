//SRM535DOV1-500 FoxAndBusiness
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class FoxAndBusiness{
	public:
	double FoxAndBusiness::minimumCost(int k,int w,vector <int> a,vector <int> p){
		int n=a.size(),i,j;
		double lo=0.0,hi=1e10;
		rep(i,200){
			double mi=(lo+hi)/2,sum=0.0;
			vector <double> ke;
			rep(j,n) ke.pb(1.0*p[j]*a[j]+3600.0-mi*a[j]);
			sort(All(ke));
			rep(j,k) sum+=ke[j];
			if(sum>0) lo=mi;else hi=mi;
		}
		return (lo+hi)*0.5*w;
	}
};
