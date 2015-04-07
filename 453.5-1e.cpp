//SRM453.5DIV1-250 MazeMaker
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
int mt[55][55];
class MazeMaker{
	public:
	int MazeMaker::longestPath(vector <string> ma,int sx,int sy,vector <int> x,vector <int> y){
		int h=ma.size(),w=ma[0].size(),n=x.size(),i,j,k,out=-5;
		vector <pint> now,next,cl;
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(ma[i][j]=='X') mt[i][j]=10000;else mt[i][j]=-1;
		}
		mt[sx][sy]=0;now.pb(mp(sx,sy));
		for(i=1;i<10000;i++){
			for(j=0;j<now.size();j++){
				for(k=0;k<n;k++){
					int nx=now[j].fi+x[k],ny=now[j].se+y[k];
					if(nx<0 || ny<0 || nx>=h || ny>=w) continue;
					if(mt[nx][ny]==-1){mt[nx][ny]=i;next.pb(mp(nx,ny));}
				}
			}
			now=next;next=cl;
		}
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(mt[i][j]==-1) return -1;
			if(mt[i][j]<10000) out>?=mt[i][j];
		}
		return out;
	}
};
