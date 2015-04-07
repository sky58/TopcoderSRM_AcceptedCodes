//SRM408DIV1-500 CandyGame

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
int huka[60];
vector <string> g;
void dep(int a,int b){
	if(huka[a]>-1) return;huka[a]=b;
	for(int i=0;i<g.size();i++) if(g[a][i]=='Y' && huka[i]==-1) dep(i,b+1);
	return;
}

int maxhu(int a){
	int ret=huka[a];
	for(int i=0;i<g.size();i++) if(g[a][i]=='Y' && huka[i]>huka[a]) ret=max(maxhu(i),ret);
	return ret;
}

class CandyGame{
	public:
	int CandyGame::maximumCandy(vector <string> gr,int a){
		long long out=0;int i;
		for(i=0;i<gr.size();i++) huka[i]=-1;g=gr;dep(a,0);
		for(i=0;i<gr.size();i++){
			if(i==a) continue;
			if(huka[i]==-1) return -1;
			out+=1<<(maxhu(i)-huka[i]);
		}
		if(out>2000000000) return -1;
		return (int)out;
	}
};
