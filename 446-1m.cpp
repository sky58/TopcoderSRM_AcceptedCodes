//SRM446DIV1-500 AntOnGraph
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef long long lint;
map<int,vector <vector <lint> > > memo;
vector <lint> cl;
lint inf=100000000;

string moji(lint a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}

vector <vector <lint> >dfs(int a){
	if(memo[a].size()) return memo[a];
	vector <vector <lint> > be,af,ret;
	be=dfs(a/2);af=dfs(a-a/2);
	int i,j,k,n=be.size();
	for(i=0;i<n;i++) ret.pb(cl);
//	for(i=0;i<n;i++) ret[i][i]=0;
	for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++){
		ret[i][j]>?=be[i][k]+af[k][j];
//		cout<<i<<' '<<j<<' '<<k<<' '<<ret[i][j]<<'\n';
	}
	return memo[a]=ret;
}

class AntOnGraph{
	public:
	string AntOnGraph::maximumBonus(vector <string> a,vector <string> b,vector <string> c,int s,int t){
		int i,j,k,l,n=a.size();lint gr[55][55];inf*=-inf;
//		if(s%2==0 && n==2) return "IMPOSSIBLE";
		vector <vector <lint> > now,next,ret;
		for(i=0;i<n;i++) cl.pb(inf);
		for(i=0;i<n;i++) now.pb(cl);
		for(i=0;i<n;i++) now[i][i]=0;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(i==j) continue;
			gr[i][j]=(a[i][j]-'0')*100+(b[i][j]-'0')*10+(c[i][j]-'0')-500;
			if(gr[i][j]==-500) gr[i][j]=inf;
		}
//		cout<<"b\n";
		for(i=0;i<n;i++) gr[i][i]=inf;
		for(i=0;i<s;i++){
			next.clear();for(j=0;j<n;j++) next.pb(cl);
			for(j=0;j<n;j++) for(k=0;k<n;k++) for(l=0;l<n;l++) next[j][k]>?=now[j][l]+gr[l][k];
			now=next;
//			for(j=0;j<n;j++) for(k=0;k<n;k++) cout<<i<<' '<<j<<' '<<k<<' '<<now[j][k]<<'\n';
		}
//		for(i=0;i<n;i++) for(j=0;j<n;j++) cout<<i<<' '<<j<<' '<<now[i][j]<<'\n';
//		cout<<"a\n";
		for(i=0;i<n;i++) now[i][i]>?=0;
		memo[1]=now;ret=dfs(t);lint out=ret[0][1];
		if(out<inf/10) return "IMPOSSIBLE";return moji(out);
	}
};
