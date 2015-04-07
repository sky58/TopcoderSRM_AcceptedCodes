//SRM594DIV1-950 FoxAndAvatar
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int w;
bool rec(int n,int m,int rest){
	if(rest<2){
		if(m==1 && (w==1 || n<=w)) return true;
		if(m==n && (w==1 || n<=w || m%w==1)) return true;
		if(m==w && n<2*w) return true;
		return false;
	}
	int nx=(n-1)/w,ny=(n-1)%w,mx=(m-1)/w,my=(m-1)%w,nn,nm;
	int dx[5],dy[5];
	dx[0]=mx-1;dx[1]=mx;dx[2]=dx[3]=nx;
	dy[0]=dy[1]=dy[2]=0;dy[3]=my+1;
	rep(i,4){
		int hx=dx[i],ly=dy[i];
		for(int lx=hx;lx>=0;lx--) REP(hy,ly,w){
			if(lx<=mx && mx<=hx && ly<=my && my<=hy) continue;
			nn=n-(hx-lx+1)*(hy-ly+1);
			if(hx>=nx) nn+=max(0,min(w-1,hy)-max(ny+1,ly)+1);
			if(ly>my) nm=m-(hy-ly+1)*max(0,min(hx,mx-1)-lx+1);
			else nm=m-(hy-ly+1)*max(0,min(hx,mx)-lx+1);
			if(rec(nn,nm,rest-1)) return true;
		}
	}
	return false;
}
class FoxAndAvatar{
	public:
	int minimalSteps(int n,int W,int x){
		w=W;
		if(n==1 && x==1) return 0;
		REP(i,1,4){
			if(rec(n,x,i)) return i;
		}
		return 4;
	}
};
