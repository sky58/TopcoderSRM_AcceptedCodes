//SRM550DIV1-300 minArea
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
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool sumi[58][58];
class RotatingBot{
	public:
	int minArea(vector<int> a){
		int n=a.size();
		if(n<2) return a[0]+1;
		if(n<3) return (a[0]+1)*(a[1]+1);
		if(n<4) return max(a[0]+1,a[2]+1)*(a[1]+1);
		//if(a.size()<5){
		int w=max(a[0],a[2])+1,h=max(a[1],a[3])+1,x=a[0],y=a[1],d=0;
		vector<int> out;
		memset(sumi,false,sizeof(sumi));sumi[x][y]=true;
		while(1){
			int j;
			//cout<<x<<' '<<y<<endl;
			for(j=0;;j++){
				int nx=x+dx[d],ny=y+dy[d];
				if(nx<0 || nx>=w || ny<0 || ny>=h) break;
				if(sumi[nx][ny]) break;
				sumi[nx][ny]=true;
				x=nx;y=ny;
			}
			if(j<1) break;
			out.pb(j);
			d=(d+1)%4;
		}
		rep(i,n){
			if(i>=out.size()) return -1;
			if(a[i]>out[i]) return -1;
			if(i<n-1 && a[i]<out[i]) return -1;
		}
		return h*w;
	}
};
