//SRM504.5DIV1-550 TheJackpotDivOne
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
class TheJackpotDivOne{
	public:
	vector<long long> find(vector<long long> a,long long b){
		int n=a.size();
		sort(All(a));
		while(a[0]<a[n-1] && b>0){
			lint hi=0,lo=0;
			rep(i,n){
				hi+=a[i]/n;lo+=a[i]%n;
			}
			hi+=lo/n;lint m=min(b,hi+1-a[0]);
			a[0]+=m;b-=m;
			sort(All(a));
			//cout<<b<<endl;rep(i,n) cout<<a[i]<<' ';cout<<endl;
		}
		rep(i,n){
			a[i]+=b/n;if(i<b%n) a[i]++;
		}
		sort(All(a));
		return a;
	}
};
