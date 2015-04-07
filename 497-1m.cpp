//SRM497DIV1-550 CssRules
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
vector <string> s;
string color[7]={"black", "blue", "gray", "green", "red", "white", "yellow"};
int dp[100][100][8][8][8];
char tag[100];string id[100];
int co[100],ha[100];
void de(string a){
	string ret="";
	for(int i=0;i<a.size();i++){
		if(a[i]=='>'){s.pb(ret);ret="";}
		else ret+=a[i];
	}
	return;
}
int dec(string a){
	for(int i=0;i<7;i++){
		if(color[i]==a) return i+1;
	}
	return 0;
}
int rec(int a,int b,int x,int y,int z){
	if(a>=b) return 0;int i,ret=100000000,fr=0;
	if(dp[a][b][x][y][z]>=0) return dp[a][b][x][y][z];
	if(ha[a]<b){
		for(i=a;i<b;i=ha[i]) fr+=rec(i,ha[i],x,y,z);return dp[a][b][x][y][z]=fr;
	}
	if(tag[a]=='b' && co[a]!=x) fr++;
	if(tag[a]=='u' && co[a]!=y) fr++;
	if(tag[a]=='i' && co[a]!=z) fr++;
	for(i=0;i<512;i++){
		int c=i%8,d=(i/8)%8,e=i/64,f=0,x1=x,y1=y,z1=z;
		if(c>0){f++;x1=c;}if(d>0){f++;y1=d;}if(e>0){f++;z1=e;}
		ret<?=f+rec(a+1,b,x1,y1,z1);
	}
//	cout<<a<<' '<<b<<' '<<x<<' '<<y<<' '<<z<<' '<<ret+fr<<endl;
	return dp[a][b][x][y][z]=ret+fr;
}
class CssRules{
	public:
	int CssRules::getMinimalCssRuleCount(vector <string> a){
		stack <int> st;int i,t=0,j,k;string x,y,z;
		string b;for(i=0;i<a.size();i++) b+=a[i];de(b);
		for(i=0;i<s.size();i++){
			if(s[i].size()<5){
				ha[st.top()]=t;st.pop();
			}
			else{
				istringstream sin(s[i]);sin>>x>>y>>z;tag[t]=x[1];id[t]=y.substr(4,y.size()-5);co[t]=dec(z.substr(13,z.size()-14));st.push(t);t++;
			}
		}
		int n=t;
//		for(i=0;i<n;i++) cout<<ha[i]<<' '<<tag[i]<<' '<<co[i]<<endl;
		for(i=0;i<100;i++) for(j=0;j<100;j++) for(k=0;k<512;k++) dp[i][j][k%8][(k/8)%8][k/64]=-1;
//		for(i=0;i<n;i=ha[i]) out+=rec(i,ha[i],0,0,0);
//		return out;
		return rec(0,n,0,0,0);
	}
};
