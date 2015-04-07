//SRM262DIV1-250 SortBooks
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
string de(string a){
	for(int i=0;i<a.size();i++){
		if(a[i]<='Z' && a[i]>='A') a[i]=(a[i]-'A')+'a';
	}
	return a;
}
bool ch(string a){
	istringstream sin(a);int t=0;string s;
	while(sin>>s){
		string s2=de(s);
		if(s2=="and" || s2=="of" || s2=="the") return true;
//		if(s2.find("and")!=string::npos) return true;
//		if(s2.find("the")!=string::npos) return true;
//		if(s2.find("or")!=string::npos) return true;
		t++;
	}
	if(t>3) return true;return false;
}
class SortBooks{
	public:
	vector <int> SortBooks::checkManually(vector <string> a,vector <string> b){
		int i;vector <int> out;
		for(i=0;i<a.size();i++){
			if(ch(a[i]) && ch(b[i])) out.pb(i);if(!ch(a[i]) && !ch(b[i])) out.pb(i);
		}
		return out;
	}
};
