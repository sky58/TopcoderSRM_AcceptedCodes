//SRM617DIV1-500 PieOrDolphin
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
int gr[55][55];int deg[55];
vector<pint> ed;
void dfs(int a){
	if(deg[a]<1) return;
	rep(i,50){
		if(gr[a][i]>0){
			ed.pb(mp(a,i));deg[a]--;deg[i]--;gr[a][i]--;gr[i][a]--;dfs(i);break;
		}
	}
}
class PieOrDolphin{
	public:
	vector<int> Distribute(vector<int> a,vector<int> b){
		int n=a.size();
		memset(gr,0,sizeof(gr));memset(deg,0,sizeof(deg));
		rep(i,n){gr[a[i]][b[i]]++;gr[b[i]][a[i]]++;deg[a[i]]++;deg[b[i]]++;}
		while(1){
			int f=-1;
			rep(i,50){if(deg[i]%2>0) f=i;}
			if(f<0) break;dfs(f);
		}
		while(1){
			int f=-1;
			rep(i,50){if(deg[i]>0) f=i;}
			if(f<0) break;dfs(f);
		}
		vector<int> out(n,0);
		rep(i,n){
			int f=0;
			rep(j,n){
				if(out[j]>0) continue;
				if(a[j]==ed[i].fi && b[j]==ed[i].se){out[j]=1;f=1;}
				if(b[j]==ed[i].fi && a[j]==ed[i].se){out[j]=2;f=1;}
				if(f>0) break;
			}
		}
		return out;
	}
};
