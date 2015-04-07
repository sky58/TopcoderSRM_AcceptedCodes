//SRM395DIV1-500 Skyscrapers
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
int memo[110][110][110];

int kei(int n,int a,int b){
	long long ret=0;
	if(n==1){
		if(a==1 && b==1) return 1;else return 0;
	}
	if(a<1 || b<1) return 0;
	if(memo[n][a][b]>-1) return memo[n][a][b];
	ret=kei(n-1,a,b-1)+kei(n-1,a-1,b)+(long long)(n-2)*kei(n-1,a,b);
	return memo[n][a][b]=(int)(ret%1000000007);
};

class Skyscrapers{
	public:
	int Skyscrapers::buildingCount(int n,int a,int b){
		memset(memo,-1,sizeof(memo));
		return kei(n,a,b);
	}
};
