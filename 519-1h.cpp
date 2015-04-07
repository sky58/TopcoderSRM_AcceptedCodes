//SRM519DIV1-900 VerySmoothDecompositions
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
int dp[12000000];
int ni[8]={1,0,2,1,3,0,2,4},sa[8]={0,1,0,1,0,2,1,0};
string dev(string a,int b){
	string ret="";int i,t=0,n,f=0;
	for(i=0;i<a.size();i++){
		t=t*10+(a[i]-'0');n=t/b;
		if(n>0) f=1;if(f>0) ret+=(n+'0');
		t%=b;
	}
	if(t!=0) return "-1";return ret;
}
class VerySmoothDecompositions{
	public:
	int VerySmoothDecompositions::solve(vector <string> a){
		int i,j,k,out=0,mo=1000000009,tw=0,th=0,fi=0,se=0,el=0;
		string b="";for(i=0;i<a.size();i++) b+=a[i];
		while(1){string c=dev(b,2);if(c=="-1") break;b=c;tw++;}
		while(1){string c=dev(b,3);if(c=="-1") break;b=c;th++;}
		while(1){string c=dev(b,5);if(c=="-1") break;b=c;fi++;}
		while(1){string c=dev(b,7);if(c=="-1") break;b=c;se++;}
		while(1){string c=dev(b,11);if(c=="-1") break;b=c;el++;}
		while(1){string c=dev(b,13);if(c=="-1") break;b=c;el++;}
		if(b!="1") return 0;
//		cout<<tw<<' '<<th<<' '<<fi<<' '<<se<<' '<<el<<endl;
		memset(dp,0,sizeof(dp));dp[0]=1;
		for(k=0;k<8;k++) for(i=0;i<=tw;i++) for(j=0;j<=th;j++){
//			cout<<k<<' '<<i<<' '<<j<<' '<<dp[i*(th+1)+j]<<endl;
			int i2=i+ni[k],j2=j+sa[k],ne=i2*(th+1)+j2;
			if(i2<=tw && j2<=th) dp[ne]=(dp[ne]+dp[i*(th+1)+j])%mo;
		}
		for(i=0;i<=tw;i++) for(j=0;j<=th;j++){
			if(th-j>fi) continue;
			int go=fi-(th-j);
			if(tw-i>go+se) continue;
			out=(out+(lint)dp[i*(th+1)+j]*(min(min(go,se),min(tw-i,go+se-tw+i))+1))%mo;
		}
		return out;
	}
};
