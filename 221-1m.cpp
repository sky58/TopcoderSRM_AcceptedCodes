//SRM221DIV1-500
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
vector <int> v;bool sumi[10];
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;dfs(v[a]);return;
}
class NumberChanger{
	public:
	int NumberChanger::transform(string a,string b){
		int n=a.size(),i,out=100000000;
		for(i=0;i<n;i++) v.pb(i);
		do{
			int ret=n;memset(sumi,false,sizeof(sumi));
			for(i=0;i<n;i++){
				if(!sumi[i]){ret--;dfs(i);}
				ret+=abs((a[i]-'0')-(b[v[i]]-'0'));
			}
			out<?=ret;
		}while(next_permutation(v.begin(),v.end()));
		return out;
	}
};
