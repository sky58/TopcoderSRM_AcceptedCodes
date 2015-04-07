//SRM400DIV1-500 RevesalChain
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
int memo[55][55][55][3];
string A,B;
int kei(int x,int a,int b,int y){
	if(memo[x][a][b][y]>-1) return memo[x][a][b][y];
	if(x==0) return 0;
	int ret=10000;
	if(A[a]==B[b]) ret<?=kei(x-1,a+1,b+1,0)+(y%2);
	if(A[a+x-1]==B[b+x-1]) ret<?=kei(x-1,a,b,0)+(y%2);
	if(A[a+x-1]==B[b]) ret<?=kei(x-1,a,b+1,1)+((y+1)%2);
	if(A[a]==B[b+x-1]) ret<?=kei(x-1,a+1,b,1)+((y+1)%2);
	return memo[x][a][b][y]=ret;
}
class ReversalChain{
	public:
	int ReversalChain::minReversal(string a,string b){
		A=a;B=b;
		memset(memo,-1,sizeof(memo));
		int out=kei(a.size(),0,0,0);
		if(out>=10000) return -1;
		return out;
	}
};
