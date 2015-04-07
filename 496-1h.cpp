//SRM496DIV1-950 YetAnotherHamiltonianPath
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
int lca(string a,string b){
	int i;
	for(i=0;i<a.size() && i<b.size();i++){
		if(a[i]!=b[i]) break;
	}
	return i;
}
class YetAnotherHamiltonianPath{
	public:
	int YetAnotherHamiltonianPath::leastCost(vector <string> a){
		int out=0,n=a.size(),i;string s=a[0],g=a[1];
		for(i=0;i<n;i++) out+=(i<2?1:2)*a[i].size()*a[i].size();
		sort(a.begin(),a.end());a.pb(a[0]);
		for(i=0;i<n;i++) out-=lca(a[i],a[i+1])*lca(a[i],a[i+1]);
		return out+lca(s,g)*lca(s,g);
	}
};
