//SRM440DIV1-500 MazeWandering
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
int f=0,h,w;
long long out=0;
int dp[60][60];
vector <string> a;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int dfs(int x,int y,int p){
	int i,ret=1;
	for(i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(i+p==3 || nx<0 || nx>=h || ny<0 || ny>=w) continue;
		if(a[nx][ny]=='X') continue;
		ret+=(dfs(nx,ny,i)+1);
	}
	return dp[x][y]=ret;
}
void dfs2(int x,int y,int c,int p){
	c+=dp[x][y];out+=c;f++;int i;
	for(i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(i+p==3 || nx<0 || nx>=h || ny<0 || ny>=w) continue;
		if(a[nx][ny]=='X') continue;
		dfs2(nx,ny,c,i);
	}
	return;
}
class MazeWandering{
	public:
	double MazeWandering::expectedTime(vector <string> A){
		a=A;h=a.size();w=a[0].size();
		int i,j,x,y;
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(a[i][j]=='*'){x=i;y=j;}
		}
		for(i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
			if(a[nx][ny]=='X') continue;
			dfs(nx,ny,i);
		}
//		return 0.0;
		dfs2(x,y,0,4);
		return 1.0*out/f;
	}
};
