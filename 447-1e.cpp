//SRM447DIV1-250 KnightTour
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
class KnightsTour{
	public:
	int KnightsTour::visitedPositions(vector <string> a){
		int i,j,nx,ny,out=1;
		for(i=0;i<8;i++) for(j=0;j<8;j++){
			if(a[i][j]=='K'){nx=i;ny=j;}
		}
//		cout<<nx<<' '<<ny<<'\n';
		while(1){
//			cout<<nx<<' '<<ny<<'\n';
			vector <pint> f;
			for(i=0;i<8;i++){
				int x=nx+dx[i],y=ny+dy[i],t=0;
				if(x<0 || y<0 || x>=8 || y>=8) continue;
				if(a[x][y]=='*') continue;
//				cout<<i<<' '<<x<<' '<<y<<'\n';
				for(j=0;j<8;j++){
					int xx=x+dx[j],yy=y+dy[j];
					if(xx>=0 && yy>=0 && xx<8 && yy<8) if(a[xx][yy]=='.') t++;
				}
				f.pb(mp(t,x*8+y));
			}
			if(f.size()==0) break;
			sort(f.begin(),f.end());
			a[nx][ny]='*';nx=f[0].se/8;ny=f[0].se%8;a[nx][ny]='K';out++;
		}
		return out;
	}
};
