//SRM606DIV1-950 Subcube
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
lint di[58][58],d2[10][10];
int px[8]={0,0,0,0,1,1,1,1},py[8]={0,0,1,1,0,0,1,1},pz[8]={0,1,0,1,0,1,0,1};
int pos[10];
int n;lint bai=-1;
lint sq(lint a){return a*a;}
set<lint> s;
void rec(int a){
	if(a>=n){
		lint t=0;
		rep(i,8){
			if(pos[i]>=0) t+=(1LL<<pos[i]);
		}
		s.insert(t);return;
	}
	rec(a+1);
	rep(i,8){
		if(pos[i]>=0) continue;
		int f=0;
		if(bai<0){
			rep(j,8){
				if(pos[j]>=0){
					if(di[a][pos[j]]%d2[i][j]>0) f=1;
					else bai=di[a][pos[j]]/d2[i][j];
				}
			}
			if(f<1){
				pos[i]=a;rec(a+1);bai=-1;pos[i]=-1;
			}
		}
		else{
			rep(j,8){
				if(pos[j]>=0){
					if(bai*d2[i][j]!=di[a][pos[j]]) f=1;
				}
			}
			if(f<1){
				pos[i]=a;rec(a+1);pos[i]=-1;
			}
		}
	}
}
class Subcube{
	public:
	long long getCount(vector<int> x,vector<int> y,vector<int> z){
		n=x.size();
		rep(i,n) rep(j,n) di[i][j]=sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]);
		rep(i,8) rep(j,8) d2[i][j]=sq(px[i]-px[j])+sq(py[i]-py[j])+sq(pz[i]-pz[j]);
		memset(pos,-1,sizeof(pos));
		rec(0);
		return (lint)s.size()-1;
	}
};
