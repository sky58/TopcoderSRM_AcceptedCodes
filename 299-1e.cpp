//SRM299DIV1-250 Projections
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
//bool sumi[55][55];
class Projections{
	public:
	vector <int> Projections::count(string a,string b){
		int n=a.size(),m=b.size(),i,j,c=0,d=0,t=0;vector <int> out;
		//memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i]=='.' || b[j]=='.') t++;
		}
		for(i=0;i<n;i++){if(a[i]=='x') c++;}for(i=0;i<m;i++){if(b[i]=='x') d++;}
		out.pb(max(c,d));out.pb(m*n-t);return out;
	}
};
