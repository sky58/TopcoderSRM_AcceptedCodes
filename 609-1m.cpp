//SRM609DIV1-500 PackingBallsDiv1
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<lint> x,am;
class PackingBallsDiv1{
	public:
	int minPacks(int k,int a,int b,int c,int d){
		x.pb(a);
		rep(i,k-1){
			x.pb((x[i]*b+c)%d+1);
		}
		lint out=k,sum=0;
		rep(i,k){
			//cout<<x[i]<<endl;
			sum+=x[i]/k;//ma=max(ma,x[i]%k);
			am.pb(x[i]%k);
		}
		sort(All(am));
		rep(i,k) out=min(out,am[i]+k-i-1);
		return (int)(out+sum);
	}
};
