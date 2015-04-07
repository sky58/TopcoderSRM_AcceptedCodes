//SRM464DIV1-550 ColorfulDecoration
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
vector <int> x,y;int n;
int dist(int a,int b){return max(abs(x[a]-x[b]),abs(y[a]-y[b]));}
bool ch(int a){
	int gra[110][110];bool ba[110];int i,j,k;
	for(i=0;i<110;i++) for(j=0;j<110;j++) gra[i][j]=10000;
	memset(ba,false,sizeof(ba));
	for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
//		if(dist(i,j)<a && dist(i+n,j)<a && dist(i+n,j+n)<a && dist(i,j+n)<a) return false;
	}
	for(i=0;i<2*n;i++) for(j=0;j<n;j++){
		if((i-j)%n==0) continue;
		if(dist(i,j+n)<a) gra[i][j]=1;
		if(dist(i,j)<a) gra[i][j+n]=1;
	}
//	for(i=0;i<n;i++){if(ba[i] && ba[i+n]) return false;}
	for(k=0;k<2*n;k++) for(i=0;i<2*n;i++) for(j=0;j<2*n;j++) gra[i][j]<?=gra[i][k]+gra[k][j];
	for(i=0;i<n;i++){if(gra[i][n+i]<1000 && gra[n+i][i]<1000) return false;}
	return true;
}
class ColorfulDecoration{
	public:
	int ColorfulDecoration::getMaximum(vector <int> xa,vector <int> ya,vector <int> xb,vector <int> yb){
		n=xa.size();int i,a=0,b=1000000000;
		for(i=0;i<n;i++){x.pb(xa[i]);y.pb(ya[i]);}for(i=0;i<n;i++){x.pb(xb[i]);y.pb(yb[i]);}
		while(a<b){int c=(a+b+1)/2;if(ch(c)) a=c;else b=c-1;}
		return a;
	}
};
