//SRM429DIV1-500(DIV2-1000) IngredientProporionsÅièëÇ´íºÇµÅj
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
typedef long long lint;
lint bo[12],si[12];
int n;int hyo[12][12];
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
void dfs(lint b,lint s,int a,int p){
	bo[a]=b;si[a]=s;
	for(int i=0;i<n;i++){
		if(i==p) continue;
		if(hyo[a][i]>0) dfs(b*hyo[a][i],s*hyo[i][a],i,a);
	}
	return;
}
class IngredientProportions{
	public:
	vector <int> IngredientProportions::getMasses(vector <string> a){
		int i;lint lcm=1;vector <int> out;n=a.size()+1;
		for(i=0;i<n-1;i++){
			hyo[(a[i][1]-'0')][(a[i][8]-'0')]=a[i][13]-'0';
			hyo[(a[i][8]-'0')][(a[i][1]-'0')]=a[i][15]-'0';
		}
		dfs(1,1,0,20);
		for(i=0;i<n;i++) lcm=lcm/gcd(lcm,bo[i])*bo[i];
		for(i=0;i<n;i++) si[i]=lcm/bo[i]*si[i];
		lint gc=si[0];
		for(i=0;i<n;i++) gc=gcd(gc,si[i]);
		for(i=0;i<n;i++) out.push_back((int)(si[i]/gc));
		return out;
	}
};
