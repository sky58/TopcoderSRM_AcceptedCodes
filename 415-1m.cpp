//SRM415DIV1-500 CollectingPostmarks
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
typedef pair<int,int> pint;
vector <pint> mae,ato;
int bs(int va,int a,int b){
	if(a==b) return ato[a].se;
	int c=(a+b+1)/2;
	if(ato[c].fi<va) return bs(va,c-1,b);return bs(va,a,c);
}
class CollectingPostmarks{
	public:
	int CollectingPostmarks::amountOfMoney(vector <int> a,vector <int> b,vector <int> c,int d){
		int n=a.size(),x=n/2,y=n-n/2,i,j,kei=0,out=2000000000,val=0;
		for(i=0;i<n;i++) val+=c[i];if(val<d) return -1;
		if(d==0) return 0;
		for(i=0;i<b.size();i++) kei+=a[b[i]];
		if(n==1) return a[0]-kei;
		
		for(i=0;i<(1<<x);i++){
			int va=0,pl=0;
			for(j=0;j<x;j++){
				if(i&(1<<j)){va+=c[j];pl+=a[j];}
			}
			mae.pb(mp(va,pl));
		}
		for(i=0;i<(1<<y);i++){
			int va=0,pl=0;
			for(j=0;j<y;j++){
				if(i&(1<<j)){va+=c[j+x];pl+=a[j+x];}
			}
			ato.pb(mp(va,pl));
		}
		sort(ato.begin(),ato.end());reverse(ato.begin(),ato.end());
		sort(mae.begin(),mae.end());reverse(mae.begin(),mae.end());
		for(i=1;i<ato.size();i++) ato[i].se<?=ato[i-1].se;
		for(i=1;i<mae.size();i++) mae[i].se<?=mae[i-1].se;
		for(i=0;i<mae.size();i++){
			if(mae[i].fi+ato[0].fi<d) continue;
			out<?=mae[i].se+bs(d-mae[i].fi,ato.size()-1,0);
		}
		return max(0,out-kei);
	}
};
