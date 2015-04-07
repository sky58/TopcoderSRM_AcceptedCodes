//SRM241DIV1-1000 PetternCutting
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
vector <lint> pa;int w,h,cn=0;
vector <string> rot(vector <string> a){
	vector <string> ret;
	int i,j,x=a.size(),y=a[0].size();
	for(i=0;i<y;i++){
		string c="";for(j=0;j<x;j++) c+=a[j][y-i-1];ret.pb(c);
	}
	return ret;
}
void view(lint a){
	int i,j;
	for(i=0;i<w;i++){
		for(j=0;j<h;j++){if(a&(1LL<<(i*h+j))) cout<<'X';else cout<<'.';}cout<<endl;
	}
	cout<<endl;return;
}
int dfs(lint a,int b){
	if(b>=w*h*4) return 0;
	int ret=dfs(a,b+1);
	if(ret>=(w*h-b/4)/cn) return ret;
	if(pa[b]>-1) if(!(a&pa[b])) ret>?=dfs(a+pa[b],b+1)+1;
	return ret;
}
class PatternCutting{
	public:
	int PatternCutting::getMax(int W,int H,vector <string> a){
		w=W;h=H;int w1=a.size(),h1=a[0].size(),i,j,k,l,m;
		for(i=0;i<w1;i++) for(j=0;j<h1;j++){if(a[i][j]=='X') cn++;}
		if(w1*h1<3) return (w*h)/(w1*h1);
		for(i=0;i<w;i++) for(j=0;j<h;j++) for(k=0;k<4;k++){
			a=rot(a);int w2=a.size(),h2=a[0].size();lint t=0;
			if(i+w2>w || j+h2>h){pa.pb(-1);continue;}
			for(l=0;l<w2;l++) for(m=0;m<h2;m++) if(a[l][m]=='X') t+=1LL<<((i+l)*h+j+m);pa.pb(t);
			//view(t);
		}
		return dfs(0,0);
	}
};
