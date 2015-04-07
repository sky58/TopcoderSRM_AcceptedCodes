//SRM556DIV1-250 XorTravelingSalesman
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool can[55][1050];
vector <pint> now,next,cl;
void aedge(int x,int y){
	if(can[x][y]) return;
	next.pb(mp(x,y));can[x][y]=true;return;
}
class XorTravelingSalesman{
	public:
	int XorTravelingSalesman::maxProfit(vector <int> a,vector <string> b){
		int i,j,n=a.size(),out=0;
		memset(can,false,sizeof(can));
		aedge(0,a[0]);now=next;next=cl;
		while(now.size()>0){
			rep(i,now.size()){
				int x=now[i].fi,y=now[i].se;
				rep(j,n){
					if(b[x][j]=='Y') aedge(j,y^a[j]);
				}
			}
			now=next;next=cl;
		}
		rep(i,n) rep(j,1024){
			if(can[i][j]) out>?=j;
		}
		return out;
	}
};
