//SRM223DIV1-1000 RevolvingDoors
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
bool sumi[55][55][1050];
int bad[55][55][1050];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},dx2[4]={1,-1,-1,1},dy2[4]={1,1,-1,-1},ne[4]={1,2,3,0};
int ma[55][55];bool su[55][55];
vector <vector <int> > now,next,cl;
vector <pint> no,nex,c;
void aedge(int a,int b){
	if(su[a][b]) return;
	nex.pb(mp(a,b));su[a][b]=true;return;
}
void aedge1(int a,int b,int c){
	if(sumi[a][b][c]) return;
	vector <int> d;d.pb(a);d.pb(b);d.pb(c);now.pb(d);sumi[a][b][c]=true;
	return;
}
void aedge2(int a,int b,int c){
	if(sumi[a][b][c]) return;
	vector <int> d;d.pb(a);d.pb(b);d.pb(c);next.pb(d);sumi[a][b][c]=true;
	return;
}
class RevolvingDoors{
	public:
	int RevolvingDoors::turns(vector <string> a){
		int n=a.size(),m=a[0].size(),i,j,k,l,o=0,sx,sy,gx,gy,fl=0;
		for(i=0;i<55;i++) for(j=0;j<55;j++) ma[i][j]=15;
		memset(sumi,false,sizeof(sumi));memset(bad,0,sizeof(bad));
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='O'){ma[i][j]=o;o++;}
			if(a[i][j]=='S'){sx=i;sy=j;}
			if(a[i][j]=='E'){gx=i;gy=j;}
		}
		memset(su,false,sizeof(su));su[sx][sy]=true;no.pb(mp(sx,sy));
		while(no.size()>0){
			for(i=0;i<no.size();i++){
				int x=no[i].fi,y=no[i].se;if(x==gx && y==gy) fl=1;
				for(j=0;j<4;j++){
					int nx=x+dx[j],ny=y+dy[j];//cout<<nx<<' '<<ny<<endl;
					if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
					if(a[nx][ny]=='#' || a[nx][ny]=='O') continue;
					aedge(nx,ny);
				}
			}
			no=nex;nex=c;
		}
		if(fl<1) return -1;
		aedge1(sx,sy,0);
		for(i=0;now.size()>0;i++){
			for(j=0;j<now.size();j++){
				int x=now[j][0],y=now[j][1],z=now[j][2];if(x==gx && y==gy) return i;
//				cout<<x<<' '<<y<<' '<<z<<endl;
				for(k=0;k<4;k++){
					int nx=x+dx[k],ny=y+dy[k];
					if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
					if(a[nx][ny]=='#' || a[nx][ny]=='O') continue;
					if(sumi[nx][ny][z]) continue;
					if(bad[nx][ny][z]>0) continue;int f=0;
					if(bad[nx][ny][z]==0){
					for(l=0;l<4;l++){
						int mx=nx+dx[l],my=ny+dy[l];
						if(mx<0 || my<0 || mx>=n || my>=m) continue;
						int ka=ma[mx][my];if(ka>12) continue;
						if(!(z&(1<<ka))){
							if(a[nx][ny]=='|' || a[nx][ny]=='-') f=1;
						}
						else{
							if(l%2==0){
								if(a[mx][my+1]=='-') f=1;
							}
							else{
								if(a[mx+1][my]=='|') f=1;
							}
						}
					}
//					if(f>0){bad[nx][ny][z]=1;continue;}else bad[nx][ny][z]=-1;
					}
					if(f>0){bad[nx][ny][z]=1;continue;}else bad[nx][ny][z]=-1;
					aedge1(nx,ny,z);
				}
				for(k=0;k<4;k++){
					int nx=x+dx2[k],ny=y+dy2[k];
					if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
					int ka=ma[nx][ny];if(ka>12) continue;
					if(z&(1<<ka)){
						if(a[x+dx[k]][y+dy[k]]=='-' || a[x+dx[k]][y+dy[k]]=='|'){
							aedge2(x+dx[ne[k]],y+dy[ne[k]],z-(1<<ka));
						}
						else{
							aedge2(x+dx[k],y+dy[k],z-(1<<ka));
						}
					}
					else{
						if(a[x+dx[k]][y+dy[k]]=='-' || a[x+dx[k]][y+dy[k]]=='|'){
							aedge2(x+dx[k],y+dy[k],z+(1<<ka));
						}
						else{
							aedge2(x+dx[ne[k]],y+dy[ne[k]],z+(1<<ka));
						}
					}
				}
			}
			now=next;next=cl;
		}
		return -1;
	}
};
