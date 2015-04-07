//SRM449.5DIV1-450 TransportationNetwork
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
typedef pair<double,int> pint;
class TransportationNetwork{
	public:
	double TransportationNetwork::minCost(vector <int> x,vector <int> y,double a,double b){
		int i,j,n=x.size(),t=n;
		double out=b*n,kei=0.0;
		vector <pint> ed;vector <int> tr;
		if(n==1) return 0.0;
		for(i=0;i<n;i++) tr.pb(i);
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			ed.pb(mp(a*sqrt(1.0*(x[j]-x[i])*(x[j]-x[i])+1.0*(y[j]-y[i])*(y[j]-y[i])),j*1000+i));
		}
		sort(ed.begin(),ed.end());
		for(i=0;t>1;i++){
			int w=ed[i].se/1000,z=ed[i].se%1000,c=tr[z];double co=ed[i].fi;
			if(tr[w]==tr[z]) continue;t--;kei+=co;
			for(j=0;j<n;j++){
				if(tr[j]==c) tr[j]=tr[w];
			}
			out<?=(kei+b*t);
		}
		return min(out,kei);
	}
};
