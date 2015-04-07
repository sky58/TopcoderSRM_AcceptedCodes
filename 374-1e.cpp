//SRM374DIV1-275(DIV2-500) SyllableSorting
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
vector <string> a;
vector <vector <string> > b;
vector <vector <string> > bb;
bool aru(char c){
	if(c=='a' || c=='e' || c=='o' || c=='u' || c=='i') return true;return false;
}
vector <string> sol(string c){
	vector <string> ret;string s;
	for(int i=0;i<c.size();i++){
		s+=c[i];
		if(aru(c[i])){
			if(i<c.size()-1) if(aru(c[i+1])) continue;
			ret.pb(s);s="";
		}
	}
	bb.pb(ret);sort(ret.begin(),ret.end());return ret;
}
bool com(int x,int y){
	for(int i=0;i<b[x].size() && i<b[y].size();i++){
		if(b[x][i]>b[y][i]) return true;
		if(b[x][i]<b[y][i]) return false;
	}
	if(b[x].size()>b[y].size()) return true;
	if(b[x].size()<b[y].size()) return false;
	for(int i=0;i<bb[x].size() && i<bb[y].size();i++){
		if(bb[x][i]>bb[y][i]) return true;
		if(bb[x][i]<bb[y][i]) return false;
	}
	if(bb[x].size()>bb[y].size()) return true;
	if(bb[x].size()<bb[y].size()) return false;

	if(a[x]<a[y]) return false;return true;
}
class SyllableSorting{
	public:
	vector <string> SyllableSorting::sortWords(vector <string> A){
		a=A;int i,j,d,n=a.size();vector <int> c;vector <string> out;
		for(i=0;i<n;i++) b.pb(sol(a[i]));
//		for(i=0;i<n;i++) for(j=0;j<b[i].size();j++) cout<<b[i][j]<<'\n';
		for(i=0;i<n;i++) c.pb(i);
		for(i=0;i<100;i++) for(j=0;j<n-1;j++){
			if(com(c[j],c[j+1])){d=c[j];c[j]=c[j+1];c[j+1]=d;}
		}
		for(i=0;i<n;i++) out.pb(a[c[i]]);
		return out;
	}
};
