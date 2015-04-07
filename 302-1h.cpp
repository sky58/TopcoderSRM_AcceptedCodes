//SRM302DIV1-900 JoinedString
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
vector <string> a;string dp[4200][15];string ma2[15][15];
bool hu(int x,int y){
	if(a[x]==a[y]){
		if(x>y) return true;return false;
	}
	int n=a[x].size(),m=a[y].size(),i;
	for(i=0;i<=n-m;i++){
		if(a[y]==a[x].substr(i,m)) return true;
	}
	return false;
}
string ma(string x,string y){
	int n=x.size(),m=y.size(),i;
	for(i=m;i>=0;i--){
		if(i>n) continue;
		if(x.substr(n-i,i)==y.substr(0,i)) return y.substr(i,m-i);
	}
	return y;
}
string smin(string x,string y){
	if(x[0]>'Z') return y;if(y[0]>'Z') return x;
	if(x.size()<y.size()) return x;
	if(x.size()>y.size()) return y;
	if(x>y) return y;return x;
}
class JoinedString{
	public:
	string JoinedString::joinWords(vector <string> A){
		a=A;int i,j,k,n=a.size(),t=0;string out="";out+=('Z'+1);
		for(i=0;i<4200;i++) for(j=0;j<15;j++) dp[i][j]=out;
		for(i=0;i<n;i++) for(j=0;j<n;j++){if(i!=j && hu(i,j)) t|=(1<<j);ma2[i][j]=ma(a[i],a[j]);}
		for(i=0;i<n;i++){if(!(t&(1<<i))) dp[t+(1<<i)][i]=a[i];}
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++){
			if(dp[i][j][0]>'Z') continue;
			for(k=0;k<n;k++){
				if(!(i&(1<<k))) dp[i+(1<<k)][k]=smin(dp[i+(1<<k)][k],dp[i][j]+ma2[j][k]);
			}
		}
		for(i=0;i<n;i++) out=smin(out,dp[(1<<n)-1][i]);return out;
	}
};
