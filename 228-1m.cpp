//SRM228DIV1-400 BagsOfGold
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
vector <int> f;int memo[60][60];int n;
int kei(int a,int b){
	if(memo[a][b]>-1) return memo[a][b];
	if((b-a)%2==n%2){
		if(a==b) return 0;
		return memo[a][b]=min(kei(a+1,b),kei(a,b-1));
	}
	else{
		if(a==b) return f[a];
		return memo[a][b]=max(kei(a+1,b)+f[a],kei(a,b-1)+f[b]);
	}
}
class BagsOfGold{
	public:
	int BagsOfGold::netGain(vector <int> A){
		int i,j,out=0;f=A;n=f.size();
		for(i=0;i<60;i++) for(j=0;j<60;j++) memo[i][j]=-1;
		for(i=0;i<n;i++) out+=f[i];
		return kei(0,n-1)*2-out;
	}
};
