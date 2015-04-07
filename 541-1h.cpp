//SRM541DIV1-1000 XorLife
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<vector <string>,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
map<pint,lint> me;
class XorLife{
	public:
	long long XorLife::countAliveCells(vector <string> a,int b){
		if(a.size()<1) return 0;
		int h=a.size(),w=a[0].size(),i,j,k,l;lint out=0;
		if(h<1 || w<1) return 0;
		if(w*h<=9) if(me.count(mp(a,b))) return me[mp(a,b)];
		if(b<1){
			rep(i,h) rep(j,w){if(a[i][j]=='o') out++;}//return out;
		}
		else if(b%2>0){
			//vector <string> newa;
			vector <string> nf(h+2,string(w+2,'.'));
			rep(i,h+2){
				//string s="";
				rep(j,w+2){
					int t=0;
					rep(k,5){
						int x=i+dx[k]-1,y=j+dy[k]-1;
						if(x<0 || y<0 || x>=h || y>=w) continue;
						if(a[x][y]=='o') t++;
					}
					if(t%2>0) nf[i][j]='o';//else s+='.';
				}
				//newa.pb(s);
			}
			out=countAliveCells(nf,b-1);
		}
		else if(h%2>0){
			string s(w,'.');a.pb(s);out=countAliveCells(a,b);
		}
		else if(w%2>0){
			rep(i,h) a[i]+='.';out=countAliveCells(a,b);
		}
		else{
			rep(i,2) rep(j,2){
				vector <string> bf(h/2,string(w/2,'.'));
				rep(k,h/2) rep(l,w/2){
					bf[k][l]=a[i+k*2][j+l*2];
				}
				out+=countAliveCells(bf,b/2);
			}
		}
		if(w*h<=9) me[mp(a,b)]=out;
		return out;
	}
}
