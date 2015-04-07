//SRM244DIV1-300 CircleDance
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
class CircleDance{
	public:
	int CircleDance::arrangeDancers(vector <int> a){
		int i,n=a.size(),out=0;vector <int> b,c;
		sort(a.begin(),a.end());
		b.pb(a[0]);for(i=1;i<n-1;i+=2) b.pb(a[i]);b.pb(a[n-1]);
		c.pb(a[0]);for(i=2;i<n-1;i+=2) c.pb(a[i]);c.pb(a[n-1]);
		for(i=0;i<b.size()-1;i++) out>?=b[i+1]-b[i];for(i=0;i<c.size()-1;i++) out>?=c[i+1]-c[i];
		return out;
	}
};
