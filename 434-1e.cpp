//SRM434DIV1-250(DIV2-500) FindingSquareInTable
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
int out=-1,x,y;vector <string> a;
bool hei(int f){
	int ff=(int)sqrt(1.0*f);
	if(ff*ff==f) return true;return false;
}
void kei(int px,int py,int vx,int vy){
	int t=0,nx=px,ny=py;
	while(1){
		t*=10;t+=(a[nx][ny]-'0');if(hei(t)) out=max(out,t);
		nx+=vx;ny+=vy;
		if(vx==0 && vy==0) break;
		if(nx<0 || nx>=x || ny<0 || ny>=y) break;
	}
	return;
}
class FindingSquareInTable{
	public:
	int FindingSquareInTable::findMaximalSquare(vector <string> A){
		int i,j,k,l;a=A;x=a.size();y=a[0].size();
		for(i=0;i<x;i++) for(j=0;j<y;j++) for(k=-x+1;k<x;k++) for(l=-y+1;l<y;l++){
			kei(i,j,k,l);
		}
		return out;
	}
};
