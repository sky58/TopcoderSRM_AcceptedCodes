//SRM241DIV1-250 ReportAccess
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
class ReportAccess{
	public:
	vector <string> ReportAccess::whoCanSee(vector <string> a,vector <string> b,vector <string> c){
		vector <string> out;int i,j,k,n=a.size(),m=c.size();string s;
		for(i=0;i<n;i++){
			istringstream sin(b[i]);int f=0;vector <string> d;
			while(sin>>s) d.pb(s);sort(d.begin(),d.end());
//				for(j=0;j<m;j++){if(s==c[j]) f++;}
//			}
			for(j=0;j<m;j++){
				for(k=0;k<d.size();k++){if(d[k]==c[j]) break;}if(k>=d.size()) f=1;
			}
			if(f<1) out.pb(a[i]);
		}
		sort(out.begin(),out.end());return out;
	}
};
