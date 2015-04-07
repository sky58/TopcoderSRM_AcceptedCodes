//SRM418DIV1-900 Barracks

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
short memo[5010][5010];int c;
int sub(int a,int b){
	if(b<=0) return 0;
	if(a<=b) return 30000;
	a-=b;b-=a;
	return sub(a,b)+1;
}

int kei(int a,int b){
	int ret=30000;
	if(b<=0) return sub(a,c);
	if(memo[a][b]>-1) return memo[a][b];
	if(b>a){
		if(a<=c) return ret;
		return memo[a][b]=kei(a,b-a+c)+1;
	}
	if(a>c) ret=min(ret,kei(a,b-a+c)+1);ret=min(ret,sub(a,c-a+b)+1);
	return memo[a][b]=ret;
}

class Barracks{
	public:
	int Barracks::attack(int a, int b, int cc){
		int i,j,out;c=cc;
		for(i=0;i<5010;i++) for(j=0;j<5010;j++) memo[i][j]=-1;
		if(b<=a) return 1;
		out=kei(a,b-a);if(out>25000) out=-2;
		return out+1;
	}
};
