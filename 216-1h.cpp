//SRM216DIV1-1000 Roxor
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
#define ma 33
int dp[20];bool sumi[ma];
int rec(int a){
	if(dp[a]>-1) return dp[a];
	int i,j;
	memset(sumi,false,sizeof(sumi));
	rep(i,a) rep(j,a){
		sumi[rec(i)^rec(j)]=true;
	}
	rep(i,ma){
		if(!sumi[i]) return dp[a]=i;
	}
}
class Roxor{
	public:
	vector <int> Roxor::play(vector <int> a){
		vector <int> out;int i,j,k,l,n=a.size();
		rep(i,20) dp[i]=-1;rec(14);
		rep(i,n-1) REP(j,i+1,n) REP(k,j,n){
			if(a[i]<1) continue;
			vector <int> b=a;b[i]--;b[j]++;b[k]++;
			reverse(All(b));
			int t=0;
			rep(l,n){
				if(b[l]%2>0) t^=dp[l];
			}
			if(t<1){out.pb(i);out.pb(j);out.pb(k);return out;}
		}
		return out;
	}
};
