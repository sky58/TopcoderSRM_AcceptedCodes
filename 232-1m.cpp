//SRM232DIV1-650 CommunicableDisease
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
string dp[15];
vector <int> gr[15][55];
int m;bool sumi[55];
void dfs1(int a,int b){
//	cout<<a<<' '<<b<<endl;
	if(dp[a][b]=='N') return;dp[a][b]='N';
	if(a<1) return;
	for(int i=0;i<gr[a-1][b].size();i++) dfs1(a-1,gr[a-1][b][i]);
	return;
}
vector <int> dfs2(int a){
	vector <int> now,next,cl;int i,j,k;now.pb(a);
	for(i=m-1;i>=0;i--){
		memset(sumi,false,sizeof(sumi));
		for(j=0;j<now.size();j++) for(k=0;k<gr[i][now[j]].size();k++){
			int b=gr[i][now[j]][k];if(dp[i][b]!='N' && !sumi[b]){sumi[b]=true;next.pb(b);}
		}
		now=next;next=cl;
	}
	return now;
}
class CommunicableDisease{
	public:
	string CommunicableDisease::findSource(vector <string> a,string b){
		int i,j,n=a.size(),x;string s="";
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			for(j=0;sin>>x;j++) gr[j][x].pb(i);
			m=j;
		}
		for(i=0;i<n;i++) s+='I';for(i=0;i<=m;i++) dp[i]=s;
		for(i=0;i<n;i++) for(j=0;j<m;j++) gr[j][i].pb(i);
		for(i=0;i<n;i++){
			if(b[i]=='N') dfs1(m,i);
		}
		for(i=0;i<n;i++){
			if(b[i]=='C'){
				vector <int> t=dfs2(i);if(t.size()<1) return "INVALID";if(t.size()<2) dp[0][t[0]]='C';
			}
		}
		return dp[0];
	}
};
