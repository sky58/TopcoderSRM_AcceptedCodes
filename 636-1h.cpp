//SRM636DIV1-1000 Sortish
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
vector<int> zyo;
int low[19][19];
int zero[19];
bool used[2014];
int pos1[5145][14],pos2[5145][14];
int rev1[5145],rev2[5145];
int rev[(1<<14)+10];
vector<int> num1[(1<<14)+10],num2[(1<<14)+10];
vector<int> num;
class Sortish{
	public:
	long long ways(int a,vector<int> b){
		int n=0,m=b.size(),x,y;lint out=0;
		zyo.pb(1);rep(i,10) zyo.pb(zyo[i]*(i+1));
		memset(used,false,sizeof(used));
		rep(i,m){
			if(b[i]==0) zero[n++]=i;
			else used[b[i]]=true;
			REP(j,i+1,m) a-=(b[i]>0 && b[j]>0 && b[i]<b[j]);
		}
		rep(i,m){if(!used[i+1]) num.pb(i+1);}
		memset(low,0,sizeof(low));
		rep(i,n) rep(j,n){
			rep(k,zero[i]) low[i][j]+=(b[k]>0 && b[k]<num[j]);
			REP(k,zero[i]+1,m) low[i][j]+=(b[k]>num[j]);
		}
		x=n/2;y=n-x;
		vector<int> t;rep(i,x) t.pb(i);
		for(int i=0;;i++){
			rev1[i]=0;
			rep(j,x-1) REP(k,j+1,x) rev1[i]+=(t[j]<t[k]);
			rep(j,x) pos1[i][j]=t[j];
			if(!next_permutation(All(t))) break;
		}
		t.clear();rep(i,y) t.pb(i);
		for(int i=0;;i++){
			rev2[i]=0;
			rep(j,y-1) REP(k,j+1,y) rev2[i]+=(t[j]<t[k]);
			rep(j,y) pos2[i][j]=t[j];
			if(!next_permutation(All(t))) break;
		}
		rep(i,(1<<n)){
			if(__builtin_popcount(i)!=x) continue;
			rev[i]=0;
			rep(j,n-1) REP(k,j+1,n) rev[i]+=((i&(1<<j)) && (!(i&(1<<k))));
			t.clear();rep(j,n){if((i&(1<<j))) t.pb(j);}
			rep(j,zyo[x]){
				int r=rev1[j];
				rep(k,x) r+=low[k][t[pos1[j][k]]];
				num1[i].pb(r);
			}
			sort(All(num1[i]));
		}
		rep(i,(1<<n)){
			if(__builtin_popcount(i)!=y) continue;
			t.clear();rep(j,n){if((i&(1<<j))) t.pb(j);}
			rep(j,zyo[y]){
				int r=rev2[j];
				rep(k,y) r+=low[x+k][t[pos2[j][k]]];
				num2[i].pb(r);
			}
			sort(All(num2[i]));num2[i].pb(1145141919);
		}
		rep(i,(1<<n)) rep(j,num1[i].size()){
			out+=(lower_bound(All(num2[(1<<n)-i-1]),a-num1[i][j]-rev[i]+1)-lower_bound(All(num2[(1<<n)-i-1]),a-num1[i][j]-rev[i]));
		}
		return out;
	}
};
