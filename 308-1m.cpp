//SRM308DIV1-500 CornersGame
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
typedef pair<int,int> pint;
map<lint,int> memo;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
class CornersGame{
	public:
	int CornersGame::countMoves(vector <string> ma){
		int i,j,k,l,n=6;
		vector <lint> now,next,cl;lint st=(1LL<<28)+(1LL<<29)+(1LL<<34)+(1LL<<35),go=(1LL<<0)+(1LL<<1)+(1LL<<6)+(1LL<<7);
		now.pb(st);memo[st]=1;
		for(l=0;;l++){
			for(i=0;i<now.size();i++){
				vector <int> x,y;vector <string> ma2=ma;
				for(j=0;j<36;j++){
					if(now[i]==go) return l;
					if(now[i]&(1LL<<j)){
						x.pb(j/6);y.pb(j%6);ma2[j/6][j%6]='t';
					}
				}
				for(j=0;j<4;j++) for(k=0;k<4;k++){
					int nx=x[j]+dx[k],ny=y[j]+dy[k],f=0;lint ne=now[i]-(1LL<<(x[j]*6+y[j]));
					if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
					if(ma2[nx][ny]=='.'){ne+=(1LL<<(nx*6+ny));f=1;}
					if(ma2[nx][ny]=='s' || ma2[nx][ny]=='t'){
						int ox=nx+dx[k],oy=ny+dy[k];if(ox<0 || ox>=n || oy<0 || oy>=n) continue;
						if(ma2[ox][oy]=='.'){ne+=(1LL<<(ox*6+oy));f=1;}
					}
					if(f==1) if(!memo[ne]){memo[ne]=1;next.pb(ne);}
				}
			}
			now=next;next=cl;if(now.size()==0) return -1;
		}
		return -1;
	}
};
