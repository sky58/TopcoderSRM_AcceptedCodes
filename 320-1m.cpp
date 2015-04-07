//SRM320DIV1-500 ContestSchedule
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
vector <pair<pint,int> > x;
map<int,int> dp;
class ContestSchedule{
	public:
	double ContestSchedule::expectedWinnings(vector <string> a){
		int i,j,n=a.size(),out=0;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);int b,c,d;sin>>b>>c>>d;x.pb(mp(mp(c,b),d));
		}
		sort(x.begin(),x.end());
		for(i=0;i<n;i++){
			int ret=0;
			for(j=0;j<i;j++){if(x[j].fi.fi<=x[i].fi.se) ret>?=dp[x[j].fi.fi];}
			dp[x[i].fi.fi]>?=ret+x[i].se;
		}
		map<int,int>::iterator it=dp.begin();
		while(it!=dp.end()){
//			cout<<(*it).first<<' '<<(*it).second<<endl;
			out>?=(*it).second;it++;
		}
		return 0.01*out;
	}
};
