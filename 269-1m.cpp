//SRM269DIV1-500 SecurityBunker
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
vector <int> bx,by,sx,sy;int b,s;
bool sumi[110];
bool ch(double d){
	int i,j,k;
	for(i=0;i<s;i++){
		vector <int> now,next,cl;memset(sumi,false,sizeof(sumi));
		for(j=0;j<b;j++){
			if((pow(0.0+sx[i]-bx[j],2.0)+pow(0.0+sy[i]-by[j],2.0))<=d*d){now.pb(j);sumi[j]=true;}
		}
		while(now.size()){
			for(j=0;j<now.size();j++) for(k=0;k<b;k++){
				if(sumi[k]) continue;
				if((pow(0.0+bx[now[j]]-bx[k],2.0)+pow(0.0+by[now[j]]-by[k],2.0))<=d*d){now.pb(k);sumi[k]=true;}
			}
			now=next;next=cl;
		}
		for(j=0;j<b;j++){if(!sumi[j]) return false;}
	}
	return true;
}
class SecurityBunker{
	public:
	double SecurityBunker::chooseBomb(vector <string> a){
		int i,j;double x=0.0,y=1e4;
		for(i=0;i<a.size();i++) for(j=0;j<a[0].size();j++){
			if(a[i][j]=='*'){bx.pb(i);by.pb(j);}
			if(a[i][j]=='?'){sx.pb(i);sy.pb(j);}
		}
		b=bx.size();s=sy.size();
		for(i=0;i<50;i++){
			double z=(x+y)/2;if(ch(z)) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
