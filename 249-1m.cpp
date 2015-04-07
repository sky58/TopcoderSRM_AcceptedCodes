//SRM249DIV1-500 ChatExit
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
int ha[55][55];
class ChatExit{
	public:
	vector <int> ChatExit::leaveOrder(vector <string> a){
		int n=a.size(),i,j,k,l;vector <int> out;vector <pint> ret;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);for(j=0;j<n;j++) sin>>ha[i][j];
		}
		for(i=0;i<n;i++) for(j=0;j<n;j++) ha[i][i]>?=ha[j][i];
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) for(l=0;l<n;l++){
			if(ha[i][k]>ha[j][k] && ha[i][l]<ha[j][l]) return out;
		}
		for(i=0;i<n;i++){
			int t=0;for(j=0;j<n;j++) t+=ha[i][j];ret.pb(mp(t,i));
		}
		sort(ret.begin(),ret.end());
		for(i=0;i<n;i++) out.pb(ret[i].se);return out;
	}
};
