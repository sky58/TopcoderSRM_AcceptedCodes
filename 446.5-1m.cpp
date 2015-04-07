//SRM446.5DIV1-550 CantorDust
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
class CantorDust{
	public:
	int CantorDust::occurrencesNumber(vector <string> a,int b){
		int i,j,n=a.size(),m=a[0].size(),kx=0,ky=0,c=1;
		string now="X",next,y="",x="";
		for(i=0;i<b;i++){
			next=now;for(j=0;j<c;j++) next+='.';next+=now;now=next;c*=3;
		}
		for(i=0;i<n;i++){
			int f=0;for(j=0;j<m;j++){if(a[i][j]=='X') f=1;}
			if(f==0) y+='.';else{y+='X';if(x=="") x=a[i];if(x!="" && x!=a[i]) return 0;}
		}
		if(x=="") for(i=0;i<m;i++) x+='.';
		int f=0,tx=c-m+1,ty=c-n+1;for(i=0;i<n;i++){if(y[i]=='X') f=1;}
		for(i=0;i<tx;i++){if(x==now.substr(i,m)) kx++;}
		for(i=0;i<ty;i++){if(y==now.substr(i,n)) ky++;}
		if(f==0) return tx*ty-(tx-kx)*(ty-ky);return kx*ky;
	}
};
