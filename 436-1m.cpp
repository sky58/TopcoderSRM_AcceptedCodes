//SRM436DIV1-500 DoNotTurn
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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int px[4]={0,1,0,-1};
int py[4]={1,0,-1,0};
class DoNotTurn{
	public:
	int DoNotTurn::minimumTurns(int n,int x0,int a,int b,int y0,int c,int d,int p,int m){
		long long vx=y0%p,vy=x0%p;bool sumi[260000][5];bool kabe[600][600];
		vector <pint> now,next,cl;int i,j;
		
		for(i=0;i<m;i++){
			int x=vx%n,y=vy%n;//cout<<x<<' '<<y<<"ka\n";
			if((x!=0 || y!=0) && (x!=n-1 || y!=n-1)) kabe[x][y]=true;
			vx=(vx*c+d)%p;vy=(vy*a+b)%p;
		}
//		for(i=0;i<n;i++) for(j=0;j<n;j++) if(kabe[i][j]) cout<<i<<' '<<j<<'\n';
		for(i=0;i<4;i++) now.pb(mp(0,i));
		for(i=0;i<2000;i++){
			for(j=0;j<now.size();j++){
				int x=now[j].fi/n,y=now[j].fi%n,z=now[j].se;if(x==n-1 && y==n-1) return i;
//				cout<<i<<' '<<x<<' '<<y<<' '<<z<<'\n';
				if(!sumi[x*n+y][(z+3)%4]){next.pb(mp(x*n+y,(z+3)%4));sumi[x*n+y][(z+3)%4]=true;}
				if(!sumi[x*n+y][(z+1)%4]){next.pb(mp(x*n+y,(z+1)%4));sumi[x*n+y][(z+1)%4]=true;}
				x+=px[z];y+=py[z];
				while(x>=0 && y>=0 && x<n && y<n && !kabe[x][y] && !sumi[x*n+y][z]){
					now.pb(mp(x*n+y,z));sumi[x*n+y][z]=true;x+=px[z];y+=py[z];
				}
			}
			now=next;next=cl;if(now.size()==0) return -1;
		}
	}
};
