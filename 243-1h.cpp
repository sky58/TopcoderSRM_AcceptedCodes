//SRM243DIV1-1000 TwoKings
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
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
bool so(int x,int y){
	if(x<0 || y<0 || x>99 || y>99) return true;return false;
}
bool ch(int qx,int qy,int kx,int ky){
	if(so(kx,ky)) return true;
	if(qx==kx) return true;
	if(qy==ky) return true;
	if(qx+qy==kx+ky) return true;
	if(qx-qy==kx-ky) return true;return false;
}
bool ch1(int qx,int qy,int kx,int ky,int lx,int ly){
	int i,j,k;if(so(kx,ky) || so(lx,ly)) return true;
	for(i=0;i<8;i++) for(j=0;j<105;j++){
		int x=qx+j*dx[i],y=qy+j*dy[i];
		if(x<0 || y<0 || x>99 || y>99) continue;
//		if(ch(x,y,kx,ky) && ch(x,y,lx,ly)) return true;
		int f=1;
		for(k=0;k<8;k++){
			if(!ch(x,y,kx+dx[k],ky+dy[k]) && !ch(x,y,lx,ly)) f=0;
			if(!ch(x,y,kx,ky) && !ch(x,y,lx+dx[k],ly+dy[k])) f=0;
		}
		if(f>0) return true;
	}
	return false;
}
class TwoKings{
	public:
	int TwoKings::captureKing(string a,string b,string c){
		int qx,qy,kx,ky,lx,ly,i,j,k;
		istringstream sin(a);sin>>qx>>qy;
		istringstream sin1(b);sin1>>kx>>ky;
		istringstream sin2(c);sin2>>lx>>ly;
		if(ch(qx,qy,kx,ky) || ch(qx,qy,lx,ly)) return 1;
		if(ch1(qx,qy,kx,ky,lx,ly)) return 2;
		for(i=0;i<8;i++) for(j=0;j<105;j++){
			int x=qx+j*dx[i],y=qy+j*dy[i];
			if(x<0 || y<0 || x>99 || y>99) continue;
			int f=0;
			for(k=0;k<8;k++){
				if(!ch1(x,y,kx,ky,lx+dx[k],ly+dy[k])) f=1;
				if(!ch1(x,y,kx+dx[k],ky+dy[k],lx,ly)) f=1;
//				if(x==23 && y==35 && f==1) cout<<k<<endl;
			}
			if(f<1) return 3;
		}
		return 4;
	}
};
