//SRM403DIV1-500 TheLuckySequence
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
typedef vector <vector <long long> > vl;
int mo=1234567891;
vector <lint> c;
map<lint,vl> memo;
vl kei(lint a){
	if(memo[a].size()) return memo[a];
	vl ret,mae,ato;int i,j,k;
	for(i=0;i<2;i++) ret.pb(c);
	mae=kei(a/2);ato=kei(a-a/2);
	for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++){
		ret[i][j]=(ret[i][j]+(mae[i][k]*ato[k][j])%mo)%mo;
	}
	return memo[a]=ret;
}
int top(int a){
	while(a>10) a/=10;return a;
}
bool unluc(int a){
	while(a>0){
		if(a%10!=4 && a%10!=7) return true;a/=10;
	}
	return false;
}
class TheLuckySequence{
	public:
	int TheLuckySequence::count(vector <int> a,int b){
		vl iti,ret;lint out=0;int i,j;
		for(i=0;i<2;i++) c.pb(0);
		for(i=0;i<2;i++) iti.pb(c);
		
		sort(a.begin(),a.end());
		for(i=0;i<a.size();i++){
			if(i>0 && a[i]==a[i-1]) continue;
			if(unluc(a[i])) continue;
			if(top(a[i])==4 && a[i]%10==4) iti[0][0]++;
			if(top(a[i])==4 && a[i]%10==7) iti[0][1]++;
			if(top(a[i])==7 && a[i]%10==4) iti[1][0]++;
			if(top(a[i])==7 && a[i]%10==7) iti[1][1]++;
		}
		memo[1]=iti;ret=kei(b);
		for(i=0;i<2;i++) for(j=0;j<2;j++) out=(out+ret[i][j])%mo;
		return (int)out;
	}
};
