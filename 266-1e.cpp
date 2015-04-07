//SRM266DIV1-300 ExploringEuropa
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
class ExploringEuropa{
	public:
	int ExploringEuropa::travelTime(string a,int b){
		vector <int> v;int i;
		for(i=0;i<a.size();i++){if(a[i]=='V') v.pb(i);}
		if(v.size()==1) return b*5+v[0];
		if(v[1]>=v[0]+b*2) return b*5+v[0];int out=b*5+v[0];
//		int t=2*v[0]-v[1]+2*b,out=b*5+v[0];
//		for(i=1;i<v.size();i++){if(v[i]<=v[0]+b) out<?=v[0]*2+b*5-v[i];}
//		out<?=v[1]+3*b+abs(v[1]-t);return out;
		for(i=1;i<a.size() && v[i]<=v[0]+2*b;i++){
			int t=2*v[0]-v[i]+2*b;out<?=v[i]+3*b+abs(v[i]-t);
		}
		return out;
	}
};
