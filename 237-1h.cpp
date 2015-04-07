//SRM237DIV1-900 MirrorPlacement
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
typedef pair<pint,int> tint;
bool sumi1[55][55][4],sumi2[55][55][4];
vector <tint> now,next,cl;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void aedge1(int x,int y,int z){
	if(!sumi1[x+2][y+2][z]){sumi1[x+2][y+2][z]=true;now.pb(mp(mp(x,y),z));}return;
}
void aedge2(int x,int y,int z){
	if(!sumi2[x+2][y+2][z]){sumi2[x+2][y+2][z]=true;next.pb(mp(mp(x,y),z));}return;
}
class MirrorPlacement{
	public:
	int MirrorPlacement::mirrors(vector <string> a){
		int f=0,h=a.size(),w=a[0].size(),i,j,gx,gy,k,l,gz;
		memset(sumi1,false,sizeof(sumi1));memset(sumi2,false,sizeof(sumi2));
		for(i=0;i<w;i++){if(a[0][i]=='.'){if(f<1){f=1;aedge1(0,i,1);}else{gx=0;gy=i;gz=3;}}}
		for(i=0;i<w;i++){if(a[h-1][i]=='.'){if(f<1){f=1;aedge1(h-1,i,3);}else{gx=h-1;gy=i;gz=1;}}}
		for(i=0;i<h;i++){if(a[i][0]=='.'){if(f<1){f=1;aedge1(i,0,0);}else{gx=i;gy=0;gz=2;}}}
		for(i=0;i<h;i++){if(a[i][w-1]=='.'){if(f<1){f=1;aedge1(i,w-1,2);}else{gx=i;gy=w-1;gz=0;}}}
//		cout<<gx<<' '<<gy<<' '<<gz<<endl;
		for(i=0;now.size()>0;i++){
			for(j=0;j<now.size();j++){
				int x=now[j].fi.fi,y=now[j].fi.se,z=now[j].se;
//				cout<<i<<' '<<x<<' '<<y<<' '<<z<<endl;
				if(x==gx+dx[z] && y==gy+dy[z] && z==gz) return i;
				if(x<0 || y<0 || x>=h || y>=w) continue;
				if(a[x][y]=='#') continue;
				else if(a[x][y]=='/'){
					int nz=3-z;aedge1(x+dx[nz],y+dy[nz],nz);
				}
				else if(a[x][y]=='`'){
					int nz=z^1;aedge1(x+dx[nz],y+dy[nz],nz);
				}
				else{
					int nz=3-z;aedge2(x+dx[nz],y+dy[nz],nz);
					nz=z^1;aedge2(x+dx[nz],y+dy[nz],nz);
					aedge1(x+dx[z],y+dy[z],z);
				}
			}
			now=next;next=cl;
			for(j=0;j<55;j++) for(k=0;k<55;k++) for(l=0;l<4;l++){if(sumi2[j][k][l]) sumi1[j][k][l]=true;}
		}
		return -1;
	}
};
