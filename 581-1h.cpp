//SRM581DIV1-900 YetAnotherBoardGame
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
int dx[5]={1,-1,0,0,0},dy[5]={0,0,1,-1,0};
int n,m,inf=1000;
vector <int> b,c,v;
void pe(int x,int y,int z){
	rep(i,z){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		b[nx]^=(1<<ny);
	}
	return;
}
int cal(int t,int j){
	b=c;int sum=__builtin_popcount(j);
	rep(k,m){
		if((j&(1<<k))) pe(0,k,4);
	}
	REP(k,1,n){
		v.clear();int ty=-1;
		rep(l,m){
			if((b[k-1]&(1<<l))) v.pb(l);
		}
		rep(l,v.size()){
			if((t&(1<<v[l]))){
				if(ty==0) return inf;ty=1;
			}
			else{
				if(ty==1) return inf;ty=0;
			}
		}
		rep(l,v.size()) pe(k,v[l],5-ty);sum+=v.size();
	}
	if(b[n-1]<1) return sum;return inf;
}
int cal2(int t,int j){
	b=c;int sum=__builtin_popcount(j);
	rep(k,m){
		if((j&(1<<k))) pe(0,k,5);
	}
	REP(k,1,n){
		v.clear();int ty=-1;
		rep(l,m){
			if((b[k-1]&(1<<l))) v.pb(l);
		}
		rep(l,v.size()){
			if((t&(1<<v[l]))){
				if(ty==0) return inf;ty=1;
			}
			else{
				if(ty==1) return inf;ty=0;
			}
		}
		rep(l,v.size()) pe(k,v[l],4+ty);sum+=v.size();
	}
	if(b[n-1]<1) return sum;return inf;
}
class YetAnotherBoardGame{
	public:
	int YetAnotherBoardGame::minimumMoves(vector <string> a){
		n=a.size();m=a[0].size();int out=inf;
		rep(i,n){
			int t=0;
			rep(j,m){if(a[i][j]=='W') t+=(1<<j);}
			c.pb(t);
		}
		rep(i,(1<<m)){
			int t=i;
			for(int j=t;;j=(t&(j-1))){
				out<?=cal(t,j);
				if(j<1) break;
			}
			t=(1<<m)-i;
			for(int j=t;;j=(t&(j-1))){
				out<?=cal2(t,j);
				if(j<1) break;
			}
		}
		if(out>=inf) return -1;return out;
	}
};
