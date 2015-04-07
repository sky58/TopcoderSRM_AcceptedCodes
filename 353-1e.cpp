//SRM353DIV1-250 Glossary
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
typedef pair<string,int> pint;
vector <vector <string> > al;
vector <string> ze,ko,cl,out;
string var="-------------------",spa="                   ";
string de(string a){
	string ret="";
	for(int i=0;i<a.size();i++){
		if(a[i]<='Z' && a[i]>='A') ret+=((a[i]-'A')+'a');else ret+=a[i];
	}
	return ret;
}
vector <string> sor(vector <string> a){
	int i,n=a.size();vector <string> ret;vector <pint> b;
	for(i=0;i<n;i++) b.pb(mp(de(a[i]),i));sort(b.begin(),b.end());
	for(i=0;i<n;i++) ret.pb(a[b[i].se]);return ret;
}
class Glossary{
	public:
	vector <string> Glossary::buildGlossary(vector <string> a){
		int i,j;
		for(i=0;i<26;i++) al.pb(cl);
		for(i=0;i<a.size();i++){
			char c=a[i][0];if(c<='z' && c>='a') al[(c-'a')].pb(a[i]);else al[(c-'A')].pb(a[i]);
		}
		for(i=0;i<26;i++) al[i]=sor(al[i]);//sort(al[i].begin(),al[i].end());
		for(i=0;i<13;i++){
			if(al[i].size()>0){
				string s;s+=(i+'A');ze.pb(s);ze.pb(var);
				for(j=0;j<al[i].size();j++) ze.pb("  "+al[i][j]);
			}
		}
		for(i=13;i<26;i++){
			if(al[i].size()>0){
				string s;s+=(i+'A');ko.pb(s);;ko.pb(var);
				for(j=0;j<al[i].size();j++) ko.pb("  "+al[i][j]);
			}
		}
		for(i=0;i<ze.size() || i<ko.size();i++){
			string s,t;if(i<ze.size()) s+=ze[i];if(i<ko.size()) t+=ko[i];
			while(s.size()<19) s+=" ";while(t.size()<19) t+=" ";
			out.pb(s+"  "+t);
		}
		return out;
	}
};
