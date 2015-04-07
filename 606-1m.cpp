//SRM606DIV1-450 EllysPairing
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
class EllysPairing{
	public:
	int getMax(int a,vector<int> b,vector<int> c,vector<int> d,vector<int> e){
		int n=b.size(),now=-1,num=0,sum=0,s2=0;
		rep(i,n){
			sum+=b[i];
			int t=c[i];
			rep(j,b[i]){
				if(num<1){now=t;num=1;}
				else{
					if(now==t) num++;else num--;
				}
				t=(t*d[i]+e[i])&(a-1);
			}
		}
		rep(i,n) rep(j,b[i]){
			if(now==c[i]) s2++;
			c[i]=(c[i]*d[i]+e[i])&(a-1);
		}
		if(s2*2>sum) return sum-s2;return sum/2;
	}
};
