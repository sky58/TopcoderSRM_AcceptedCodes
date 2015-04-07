//SRM345DIV1-250 Pathfinding
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
int dx[9]={-1,-1,-1,0,0,0,1,1,1};
int dy[9]={-1,0,1,-1,0,1,-1,0,1};
class Pathfinding{
	public:
	int Pathfinding::getDirections(int x,int y){
		int i,j,k;int dis[40][40];int nx[36],ny[36];
		for(i=0;i<36;i++){
			nx[i]=0;ny[i]=0;
			nx[i]+=dx[i%9];ny[i]+=dy[i%9];
			if(i%18>8) nx[i]+=x;
			if(i>17) ny[i]+=y;
//			cout<<i<<' '<<nx[i]<<' '<<ny[i]<<'\n';
		}
		for(i=0;i<40;i++) for(j=0;j<40;j++) dis[i][j]=10000000;
		for(i=0;i<36;i++) for(j=0;j<36;j++){
			int x1=nx[i],y1=ny[i],x2=nx[j],y2=ny[j];
			if(x1!=x2 && y1!=y2) continue;
			if(x1==x2){
				if(abs(x1)%2==0 && y2>=y1) dis[i][j]=y2-y1;
				if(abs(x1)%2==1 && y1>=y2) dis[i][j]=y1-y2;
			}
			if(y1==y2){
				if(abs(y1)%2==0 && x2>=x1) dis[i][j]=x2-x1;
				if(abs(y1)%2==1 && x1>=x2) dis[i][j]=x1-x2;
			}
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
		}
		for(k=0;k<36;k++) for(i=0;i<36;i++) for(j=0;j<36;j++) dis[i][j]<?=dis[i][k]+dis[k][j];
		return dis[4][31];
	}
};
