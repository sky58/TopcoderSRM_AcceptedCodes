//SRM241DIV1-500 BrokenCalculator
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
#define fi first.first
#define se first.second
#define th second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
vector <tint> now,next,cl;
bool sumi[1100][1100][5];
bool su[5];
void aedge(int a,int b,int c){
	if(!sumi[a][b][c]){
		next.pb(mp(mp(a,b),c));sumi[a][b][c]=true;
	}
	return;
}
class BrokenCalculator{
	public:
	int BrokenCalculator::fewestKeys(vector <int> a,string b,int c){
		int i,j,k;memset(su,false,sizeof(su));
		for(i=0;i<b.size();i++){
			if(b[i]=='+') su[0]=true;if(b[i]=='-') su[1]=true;if(b[i]=='*') su[2]=true;if(b[i]=='/') su[3]=true;
		}
		memset(sumi,false,sizeof(sumi));now.pb(mp(mp(0,0),0));sumi[0][0][0]=true;
		for(i=0;now.size()>0;i++){
			for(j=0;j<now.size();j++){
				int x=now[j].fi,y=now[j].se,z=now[j].th;//cout<<i<<' '<<x<<' '<<y<<' '<<z<<endl;
				if(x==c || y==c) return i;
				for(k=0;k<a.size();k++){if(y*10+a[k]<1000) aedge(x,y*10+a[k],z);}
				for(k=0;k<4;k++){
					if(!su[k]) continue;
					if(z==0) if(x+y<1000) aedge(x+y,0,k);
					if(z==1) if(x-y>=0) aedge(x-y,0,k);
					if(z==2) if(x*y<1000) aedge(x*y,0,k);
					if(z==3) if(y>0) aedge(x/y,0,k);
				}
			}
			now=next;next=cl;
		}
		return -1;
	}
}
