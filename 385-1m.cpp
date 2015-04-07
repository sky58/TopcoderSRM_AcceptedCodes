//SRM385DIV1-500 TuringMaze
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
typedef pair<int,int> pint;
#define mp make_pair
#define se second
#define fi first
#define pb push_back
vector <string> a;
int kei(int x,int y,int z){
	if(a[x][y]=='A') return 3;
	if(a[x][y]=='B') return 0;
	int s=0;
	if(z&(1<<x)) s++;if(z&(1<<(7+y))) s++;
	if((a[x][y]=='C' && s%2==0) || (a[x][y]=='D' && s%2==1)) return 1;
	return 2;
}
class TurningMaze{
	public:
	int TurningMaze::minTime(vector <string> A){
		vector <pint> now,next,cl;bool sumi[55][17000];a=A;
		int h=a.size(),w=a[0].size(),i,j;
		
		now.push_back(mp(0,0));sumi[0][0]=true;
		for(i=0;i<1000000;i++){
			for(j=0;j<now.size();j++){
				int x=now[j].fi/w,y=now[j].fi%w,z=now[j].se,n=kei(x,y,z);
//				cout<<i<<' '<<x<<' '<<y<<' '<<z<<'\n';
				if(x==h-1 && y==w-1) return i;
				if(n%2==1){
					if(x-1>=0) if(kei(x-1,y,z)%2==1 && !sumi[x*w-w+y][z]){sumi[x*w-w+y][z]=true;next.pb(mp(x*w-w+y,z));}
					if(x+1<h) if(kei(x+1,y,z)%2==1 && !sumi[x*w+w+y][z]){sumi[x*w+w+y][z]=true;next.pb(mp(x*w+w+y,z));}
				}
				if(n/2==1){
					if(y-1>=0) if(kei(x,y-1,z)/2==1 && !sumi[x*w-1+y][z]){sumi[x*w-1+y][z]=true;next.pb(mp(x*w-1+y,z));}
					if(y+1<w) if(kei(x,y+1,z)/2==1 && !sumi[x*w+1+y][z]){sumi[x*w+1+y][z]=true;next.pb(mp(x*w+1+y,z));}
				}				
				if(z&(1<<x)) z-=(1<<x);else z+=(1<<x);if(z&(1<<(7+y))) z-=(1<<(7+y));else z+=(1<<(7+y));
				if(!sumi[x*w+y][z]){sumi[x*w+y][z]=true;next.pb(mp(x*w+y,z));}
			}
			now=next;next=cl;if(now.size()==0) return -1;
		}
	}
};
