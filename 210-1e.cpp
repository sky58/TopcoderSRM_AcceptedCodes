//SRM210DIV1-250 IPConverter
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool ok(string a){
	int i,n=a.size();lint t=0;
	if(n>1 && a[0]=='0') return false;
	rep(i,n) t=t*10+(a[i]-'0');
	if(t<0 || t>255) return false;return true;
}
class IPConverter{
	public:
	vector <string> IPConverter::possibleAddresses(string a){
		int i,j,k,n=a.size();vector <string> out;
		REP(i,1,n) REP(j,1,n) REP(k,1,n){
			int l=n-i-j-k;if(l<1) continue;
			string b=a.substr(0,i),c=a.substr(i,j),d=a.substr(i+j,k),e=a.substr(i+j+k);
			if(ok(b) && ok(c) && ok(d) && ok(e)) out.pb(b+"."+c+"."+d+"."+e);
		}
		sort(All(out));return out;
	}
};
