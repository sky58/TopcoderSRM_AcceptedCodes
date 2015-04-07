//SRM227DIV1-250 CliantsList
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
typedef pair<string,string> pstr;
class ClientsList{
	public:
	vector <string> ClientsList::dataCleanup(vector <string> a){
		int n=a.size(),i;vector <string> out;vector <pstr> ret;string x,y;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>x>>y;
			if(x.substr(x.size()-1,1)==","){
//				out.pb(y+" "+x.substr(0,x.size()-1));
				ret.pb(mp(x.substr(0,x.size()-1),y));
			}
			else ret.pb(mp(y,x));
		}
		sort(ret.begin(),ret.end());
		for(i=0;i<n;i++) out.pb(ret[i].se+" "+ret[i].fi);
		return out;
	}
};
