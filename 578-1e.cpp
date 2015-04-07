//SRM578DIV1-250 GooseInZooDivOne
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
vector <int> gr[2510];
bool sumi[2510];
int t;
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;t++;
	rep(i,gr[a].size()) dfs(gr[a][i]);
	return;
}
class GooseInZooDivOne{
	public:
	int GooseInZooDivOne::count(vector <string> a,int b){
		int n=a.size(),m=a[0].size(),f=0;lint out=1,mo=1000000007;
		rep(i,n) rep(j,m) rep(k,n) rep(l,m){
			if(a[i][j]=='v' && a[k][l]=='v' && abs(i-k)+abs(j-l)<=b) gr[i*m+j].pb(k*m+l);
		}
		rep(i,n) rep(j,m){
			if(a[i][j]=='v' && !sumi[i*m+j]){
				t=0;dfs(i*m+j);
				if(t%2==1 && f==0) f=1;
				else out=(out*2)%mo;
			}
		}
		return (int)(out-1);
	}
};
