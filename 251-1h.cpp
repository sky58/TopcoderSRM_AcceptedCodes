//SRM251DIV1-1000 MusicCompilation
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
class MusicCompilation{
	public:
	vector <string> MusicCompilation::makeCompilation(vector <string> a){
		vector <string> b,c,out;string x;int i,j,y;
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);sin>>x>>y;
			if(y>1){b.pb(x);for(j=0;j<y-2;j++) c.pb(x);}
			else{for(j=0;j<y;j++) c.pb(x);}
		}
		sort(b.begin(),b.end());sort(c.begin(),c.end());
		for(i=0;i<b.size();i++) out.pb(b[i]);
		for(i=0;i<c.size();i++) out.pb(c[i]);
		for(i=0;i<b.size();i++) out.pb(b[i]);
		return out;
	}
};
