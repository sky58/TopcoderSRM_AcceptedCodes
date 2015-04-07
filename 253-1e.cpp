//SRM253DIV1-250
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
typedef pair<int,char> pint;
int d[30];
vector <pint> c;
class Decipher{
	public:
	vector <string> Decipher::decipher(vector <string> a,string b){
		int i,j,n=a.size();vector <string> out;
		for(i=0;i<26;i++) c.pb(mp(0,(i+'A')));
//		for(i=0;i<n;i++) for(j=0;j<a[i].size();j++) c[(a[i][j]-'a')]=true;
		for(i=0;i<n;i++) for(j=0;j<a[i].size();j++){
			if(a[i][j]!=' ') c[(a[i][j]-'A')].fi--;
		}
		sort(c.begin(),c.end());
		for(i=0;i<26;i++) d[(c[i].se-'A')]=i;
		for(i=0;i<n;i++){
			string e="";
			for(j=0;j<a[i].size();j++){
				if(a[i][j]==' ') e+=' ';
				else e+=b[d[(a[i][j]-'A')]];
			}
			out.pb(e);
		}
		return out;
	}
};
