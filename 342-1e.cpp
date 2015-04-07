//SRM342DIV1-250 TagalogDictonary
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
string b="abkdeghilmnzoprstuwy";
string dec(string a){
	string ret="";int t=0,i;
	while(t<a.size()){
		if(t<a.size()-1) if(a.substr(t,2)=="ng"){ret+=(11+'a');t+=2;continue;}
		for(i=0;i<20;i++){
			if(b[i]==a[t]) ret+=(i+'a');
		}
		t++;
	}
	return ret;
}
class TagalogDictionary{
	public:
	vector <string> TagalogDictionary::sortWords(vector <string> a){
		int i,n=a.size();vector <string> out;vector <pint> c;
		for(i=0;i<n;i++) c.pb(mp(dec(a[i]),i));sort(c.begin(),c.end());
		for(i=0;i<n;i++) out.pb(a[c[i].se]);return out;
	}
};
