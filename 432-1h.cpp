//SRM432DIV1-1000 BuildersCountry
#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
typedef pair<long long,int> pint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
class BuildersCountry{
	public:
	long long BuildersCountry::minCost(vector <int> a,vector <int> b,vector <int> c,vector <string> d,int co){
		vector <pint> e;vector <int> ki;long long out=0;int i,j,n=a.size(),ed=0;
		for(i=0;i<n;i++) out+=((long long)b[i]*(b[i]-1)-(long long)a[i]*(a[i]-1))*c[i]/2;
		
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			if(d[i][j]=='Y'){
				e.pb(mp(0,i*100+j));
				int x,y;if(c[i]>c[j]){x=i;y=j;}else{x=j;y=i;}
				out+=(long long)(b[x]-a[x])*a[y]*c[x];
				out+=(long long)(b[y]-a[y])*b[x]*c[y];
			}				
			else{
				long long t=(long long)co*(a[i]+a[j]);
				int x,y;if(c[i]>c[j]){x=i;y=j;}else{x=j;y=i;}
				t+=(long long)(b[x]-a[x])*a[y]*c[x];
				t+=(long long)(b[y]-a[y])*b[x]*c[y];
				e.pb(mp(t,100*i+j));
			}
		}
		
		for(i=0;i<n;i++) ki.pb(i);sort(e.begin(),e.end());
		for(i=0;i<e.size();i++){
			int x=e[i].se/100,y=e[i].se%100;long long t=e[i].fi;
			if(ki[x]==ki[y]) continue;
//			cout<<x<<' '<<y<<' '<<t<<'\n';
			int f=ki[x];
			for(j=0;j<n;j++){
				if(ki[j]==f) ki[j]=ki[y];
			}
			ed++;out+=t;if(ed==n-1) break;
		}
		return out;
	}
};
