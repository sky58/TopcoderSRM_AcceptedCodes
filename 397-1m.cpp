//SRM397DIV1-500 SumOfPowers
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
#define pb push_back
typedef long long lint;
typedef vector <lint> vl;
typedef vector <vl> vvl;
vvl tmp,iti;
vl a;
int mo=1000000007;
map<int,vvl> memo;
vvl kei(int n){
	if(memo[n].size()) return memo[n];
	vvl ret,mae,ato;ret=iti;mae=kei(n/2);ato=kei(n-n/2);
	int i,j,k,t=mae.size();
	for(i=0;i<t;i++) for(j=0;j<t;j++) for(k=0;k<t;k++)
		ret[i][j]=(ret[i][j]+mae[i][k]*ato[k][j])%mo;
	return memo[n]=ret;
}
class SumOfPowers{
	public:
	int SumOfPowers::value(int n,int k){
		vvl ret;lint out=0;int i,j;
		if(n==1) return 1;
		for(i=0;i<k+2;i++) a.pb(0);
		for(i=0;i<k+2;i++) tmp.pb(a);
		iti=tmp;tmp[k+1][k+1]=1;tmp[0][0]=1;
		for(i=k+1;i>1;i--) for(j=k+1;j>=i;j--){
			tmp[i-1][j]=(tmp[i-1][j]+tmp[i][j])%mo;
			tmp[i-1][j-1]=(tmp[i-1][j-1]+tmp[i][j])%mo;
		}
		for(i=1;i<k+2;i++) tmp[0][i]=tmp[1][i];
		for(i=0;i<k+2;i++){
//			for(j=0;j<k+2;j++) cout<<tmp[i][j]<<' ';cout<<'\n';
		}
		memo[1]=tmp;
		ret=kei(n-1);
		for(i=0;i<k+2;i++) out=(out+ret[0][i])%mo;
		return (int)(out%mo);
	}
};
