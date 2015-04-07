//SRM355DIV1-300 MixingLiquids
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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<double,double> pint;
class MixingLiquids{
	public:
	double MixingLiquids::howMuch(vector <int> a,vector <int> b,int c){
		vector <pint> d;double pa=0.01*c,miz=0.0,sio=0.0;int i,n=a.size();
		for(i=0;i<n;i++) d.pb(mp(0.01*a[i],1.0*b[i]));
		sort(d.begin(),d.end());
		if(pa<d[0].fi || pa>d[n-1].fi) return 0.0;
		if(pa==d[0].fi || pa==d[n-1].fi){
			for(i=0;i<n;i++){
				if(pa==d[i].fi) miz+=d[i].se;
			}
			return miz;
		}
		for(i=0;i<n;i++){miz+=d[i].se;sio+=d[i].se*d[i].fi;}
//		cout<<miz*pa<<' '<<sio<<'\n';
		if((miz*pa)==sio) return miz;
		if((miz*pa)>=sio){
			for(i=0;i<n;i++){
				miz-=d[i].se;sio-=d[i].se*d[i].fi;
				if((miz*pa)<=sio){
					if(d[i].fi==pa) return miz+d[i].se;
					return miz+(pa*miz-sio)/(d[i].fi-pa);
				}
			}
		}
		else{
			for(i=n-1;i>=0;i--){
				miz-=d[i].se;sio-=d[i].se*d[i].fi;
				if((miz*pa)>=sio){
					if(d[i].fi==pa) return miz+d[i].se;
					return miz+(pa*miz-sio)/(d[i].fi-pa);
				}
			}
		}
	}
};
