//SRM263DIV1-250 DVDPlayer
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
typedef pair<string,string> pint;
map<string,int> me;
vector <string> de;
int ha[55];
class DVDPlayer{
	public:
	vector <string> DVDPlayer::findMovies(vector <string> a){
		int it=1,i,n=a.size();vector <string> out;vector <pint> ret;de.pb("");
		for(i=0;i<55;i++) ha[i]=i;
		for(i=0;i<n;i++){if(!me[a[i]]){me[a[i]]=it;de.pb(a[i]);it++;}}
		for(i=0;i<n-1;i++) ha[me[a[i]]]=ha[me[a[i+1]]];ha[me[a[n-1]]]=me[a[n-1]];
		for(i=1;i<=n;i++){if(i!=ha[i]) ret.pb(mp(de[i],de[ha[i]]));}
		sort(ret.begin(),ret.end());
		for(i=0;i<ret.size();i++) out.pb(ret[i].fi+" is inside "+ret[i].se+"'s case");
		return out;
	}
};
