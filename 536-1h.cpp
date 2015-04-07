//SRM536DIV1-1000 BinaryPolynomialDivOne
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
class BinaryPolynomialDivOne{
	public:
	int BinaryPolynomialDivOne::findCoefficient(vector <int> a,long long m,long long k){
		int n=a.size(),i,j;int dp[200];
		vector <lint> now;now.pb(k);
		while(m>0){
			if(m%2>0){
				memset(dp,0,sizeof(dp));vector <lint> next;
				rep(i,now.size()) rep(j,n){
					if(a[j]<1) continue;
					dp[now[0]-now[i]+j]^=1;
				}
				for(i=0;now[0]-i>=0 && i<200;i++){
					if(dp[i]>0) next.pb(now[0]-i);
				}
				now=next;
			}
			vector <lint> next;
			rep(i,now.size()){
				if(now[i]%2<1) next.pb(now[i]/2);
			}
			now=next;m/=2;
		}
		rep(i,now.size()){if(now[i]==0) return 1;}return 0;
	}
};
