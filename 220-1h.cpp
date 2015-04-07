//SRM220DIV1-900 RearrangeFurniture
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
vector <int> a,b,c;
bool sumi[55];
void dfs(int x){
	if(!sumi[x]){sumi[x]=true;c.pb(a[x]);dfs(b[x]);}return;
}
class RearrangeFurniture{
	public:
	int RearrangeFurniture::lowestEffort(vector <int> A,vector <int> B){
		a=A;b=B;int n=a.size(),i,j,out=0,mi=100000000;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++) mi<?=a[i];
		for(i=0;i<n;i++){
			if(sumi[i]) continue;c.clear();dfs(i);
			int m=c.size();if(m<1) continue;
			sort(c.begin(),c.end());
			for(j=0;j<m;j++) out+=c[j];out+=min(c[0]+mi*(m+1),c[0]*(m-2));
		}
		return out;
	}
};
