//SRM387DIV1-300 MarblesRegroupingEasy
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
vector <string> a;int m,n;

int kei(int b){
	bool sumi[60];
	int i,j,x,y,ret=0;
	memset(sumi,false,sizeof(sumi));
	
	for(i=0;i<n;i++){
		if(i==b) continue;
		x=0;y=0;
		for(j=0;j<m;j++) if(a[i][j]!='0'){x++;y=j;}
		if(x>1) ret++;
		if(x==1){
			if(sumi[y]) ret++;else sumi[y]=true;
		}
	}
	return ret;
}

class MarblesRegroupingEasy{
	public:
	int MarblesRegroupingEasy::minMoves(vector <string> b){
		int i,out=1000000;a=b;n=b.size();m=b[0].size();
		for(i=0;i<n;i++) out=min(out,kei(i));
		return out;
	}
};
