//SRM635DIV1-500 StoryFromTCO
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
namespace MCF {
	#define MAXN 10050
	#define MAXM 500000
	#define wint int
	#define cint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 0;
	const cint cINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	cint cost[MAXM], toc, d[MAXN], pot[MAXN];
	int vis[MAXN], pree[MAXN];
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n * 4);
	}
	void ae(int u, int v, wint w, cint c) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		int i, u, v;
		wint f;
		cint c, cc;
		memset(pot, 0, n * sizeof(cint));
		
		for (bool cont = 1; cont ;) {
			cont = 0;
			for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
				if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
					pot[zu[i]] = pot[u] + cost[i]; cont = 1;
				}
			}
		}
		
		for (toc = 0, tof = 0; tof + wEPS < flo; ) {
			typedef pair<cint, int> node;
			priority_queue<node, vector<node>, greater<node> > q;
			for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
			for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
				}
			}
			if (!vis[ink]) return 0;
			f = flo - tof;
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; f = min(f, capa[i]); }
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
			tof += f;
			toc += f * (d[ink] - pot[src] + pot[ink]);
			for (u = 0; u < n; ++u) pot[u] += d[u];
		}
		return 1;
	}
}
class StoryFromTCO{
	public:
	int minimumChanges(vector<int> a,vector<int> b){
		int n=a.size(),s=n*2,t=s+1,v=t+1;vector<pint> p;
		rep(i,n) p.pb(mp(b[i],a[i]));sort(All(p));
		rep(i,n) a[i]=p[i].se,b[i]=p[i].fi;b.pb(1145141919);
		MCF::init(v);
		//rep(i,n) cout<<a[i]<<' '<<b[i]<<endl;
		rep(i,n){
			MCF::ae(s,i,1,0);MCF::ae(i+n,t,1,0);
			if(a[i]<=b[i]) MCF::ae(i,i+n,1,0);
			int f=lower_bound(All(b),a[i])-b.begin();
			//cout<<i<<' '<<f<<endl;
			if(f<n) MCF::ae(i,f+n,1,1);
			if(i<n-1) MCF::ae(i+n,i+n+1,n,0);
		}
		if(!MCF::solve(s,t,n)) return -1;
		//MCF::solve(s,t);if(MCF::tof<n) return -1;
		return MCF::toc;
	}
};
