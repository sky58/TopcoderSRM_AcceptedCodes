//SRM428DIV1-500 TheLongPalindrome
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
int mo=1234567891;
map<int,vector <vector <lint> > > memo;
vector <vector <lint> > tmp;
vector <vector <lint> > calc(int a){
	if(memo[a].size()) return memo[a];
	vector <vector <lint> > mae,ato,ret=tmp;
	int i,j,k;
	mae=calc(a/2);ato=calc(a-a/2);
	for(i=0;i<28;i++) for(j=0;j<28;j++) for(k=0;k<28;k++){
		ret[i][j]=(ret[i][j]+mae[i][k]*ato[k][j])%mo;
	}
	return memo[a]=ret;
}
class TheLongPalindrome{
	public:
	int TheLongPalindrome::count(int n,int k){
		int i;lint ret=0;
		vector <lint> cl;for(i=0;i<28;i++) cl.pb(0);
		for(i=0;i<28;i++) tmp.pb(cl);
		vector <vector <lint> > one=tmp,out;
		for(i=1;i<27;i++){one[i][i]=i;one[i-1][i]=27-i;}
		for(i=1;i<=k;i++) one[i][27]=1;one[27][27]=1;
		memo[1]=one;
		out=calc((n+1)/2);for(i=1;i<=k;i++) ret+=out[0][i];
		if(n%2==1) return (ret+out[0][27]*2)%mo;return (ret*2+out[0][27]*2)%mo;
	}
};
