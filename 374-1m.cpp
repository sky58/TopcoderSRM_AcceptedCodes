//SRM374DIV1-500 PlayerExtraction
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector <string> a;
bool sumi[55][55];
int h,w;
char c;
vector <int> dfs(int x,int y){
	vector <int> ret,cl;int i;
	for(i=0;i<5;i++) ret.pb(0);ret[1]=1000;ret[3]=1000;
//	cout<<"a\n";
	if(x<0 || y<0 || x>=w || y>=h) return ret;
//	cout<<"b\n";
	if(sumi[y][x]) return ret;
//	cout<<"c\n";
	if(a[y][x]!=c) return ret;
//	cout<<"d\n";
	sumi[y][x]=true;
	for(i=0;i<4;i++){
		cl=dfs(x+dx[i],y+dy[i]);
		ret[0]+=cl[0];ret[1]<?=cl[1];ret[1]<?=cl[1];ret[2]>?=cl[2];ret[3]<?=cl[3];ret[4]>?=cl[4];
	}
	ret[0]++;ret[1]<?=(x*2+1);ret[3]<?=(y*2+1);
	ret[2]>?=(x*2+1);ret[4]>?=(y*2+1);
//	printf("%d %d %d %d %d\n",x,y,ret[0],ret[1],ret[2]);
	return ret;
}
class PlayerExtraction{
	public:
	vector <string> PlayerExtraction::extractPlayers(vector <string> A,int C,int b){
		a=A;h=a.size();w=a[0].size();c=(C+'0');int i,j;
		vector <pint> ret;vector <string> out;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(sumi[i][j]) continue;
			vector <int> k=dfs(j,i);
//			cout<<i<<' '<<j<<' '<<k[0]<<' '<<k[1]<<' '<<k[2]<<'\n';
			if(k[0]*4>=b){
//				cout<<i<<' '<<j<<' '<<k[0]<<' '<<k[1]<<' '<<k[2]<<'\n';
				ret.pb(mp((k[1]+k[2])/2,(k[3]+k[4])/2));
			}
		}
		sort(ret.begin(),ret.end());
		for(i=0;i<ret.size();i++){
			stringstream sin;
			sin<<ret[i].fi<<' '<<ret[i].se;
			out.pb(sin.str());
		}
		return out;
	}
};
