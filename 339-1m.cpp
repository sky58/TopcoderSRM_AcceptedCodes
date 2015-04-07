//SRM339DIV1-450 TestBettingStrategy
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
#include<queue>
#include<deque>
using namespace std;
int a,b,c,d;
int zyo[20];
double memo[1100][60][15];
double kei(int x,int y,int z){
	if(x>=b) return 1.0;if(y==c) return 0.0;
	if(zyo[z]>x) return 0.0;
	if(memo[x][y][z]>-1.0) return memo[x][y][z];
	return memo[x][y][z]=0.01*d*kei(x+zyo[z],y+1,0)+0.01*(100-d)*kei(x-zyo[z],y+1,z+1);
}
class TestBettingStrategy{
	public:
	double TestBettingStrategy::winProbability(int A,int B,int C,int D){
		a=A;b=B;c=C;d=D;int i,j,k;zyo[0]=1;
		for(i=0;i<18;i++) zyo[i+1]=zyo[i]*2;
		for(i=0;i<1100;i++) for(j=0;j<60;j++) for(k=0;k<15;k++) memo[i][j][k]=-1.0;
		return kei(a,0,0);
	}
};
