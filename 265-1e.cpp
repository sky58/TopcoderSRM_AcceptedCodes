//SRM265DIV1-250 ScheduleStrength
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
//typedef pair<double,double> pdou;
typedef pair<double,string> pstr;
int w[55],l[55];
class ScheduleStrength{
	public:
	vector <string> ScheduleStrength::calculate(vector <string> a,vector <string> b){
		int i,j,n=a.size();
		memset(w,0,sizeof(w));memset(l,0,sizeof(l));vector <pstr> ret;vector <string> out;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(b[i][j]=='W') w[i]++;if(b[i][j]=='L') l[i]++;
		}
		for(i=0;i<n;i++){
			int nw=0,nl=0;
			for(j=0;j<n;j++){
				if(b[i][j]!='-'){nw+=w[j];nl+=l[j];}
				if(b[i][j]=='W') nl--;if(b[i][j]=='L') nw--;
			}
			ret.pb(mp(-1.0*nw/(nw+nl),a[i]));
		}
		sort(ret.begin(),ret.end());for(i=0;i<n;i++) out.pb(ret[i].se);
		return out;
	}
};
