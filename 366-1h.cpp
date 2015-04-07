//SRM366DIV1-1000 LateForConcert

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
using namespace std;
double memo[5][110][55][55];
int vx[4]={0,-1,1,0};int vy[4]={1,0,0,-1};
int tim,h,w;double tic,red;
vector <string> city;
double kei(int a,int t,int x,int y){
	double ret=10e10;int i;
	if(memo[a][t][x][y]>-1.0) return memo[a][t][x][y];
	if(city[x][y]=='C' && t==tim) return 0;
	if(city[x][y]=='C' || t>=tim) return 10e10;
	for(i=0;i<4;i++){
		if(i+a==3) continue;
		int nx=x+vx[i],ny=y+vy[i];
		if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
		if(city[nx][ny]=='X') continue;
		if(city[nx][ny]=='.' || city[nx][ny]=='Y' || city[nx][ny]=='C') ret<?=kei(i,t+1,nx,ny);
		if(city[nx][ny]=='S') ret<?=kei(i,t+1,nx,ny)+tic;
		if(city[nx][ny]=='T') ret<?=min(kei(i,t+2,nx,ny),kei(i,t+1,nx,ny)+0.7*red);
	}
	return memo[a][t][x][y]=ret;
}
class LateForConcert{
	public:
	double LateForConcert::bestRoute(vector <string> a,int b,double c,double d){
		city=a;tim=b;tic=c;red=d;h=a.size();w=a[0].size();int i,j;double out;
		memset(memo,-1.0,sizeof(memo));
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(city[i][j]=='Y') out=kei(4,0,i,j);
		}
		if(out>10e9) return -1;return out;
	}
};
