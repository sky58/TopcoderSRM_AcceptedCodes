//SRM243DIV1-250 Generators
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
bool sumi[2000];
class Generators{
	public:
	vector <int> Generators::find(int p){
		vector <int> out;int i,j;
		for(i=2;i<p;i++){
			memset(sumi,false,sizeof(sumi));int f=0,t=1;
			for(j=0;j<p-1;j++){
				if(sumi[t]) f=1;sumi[t]=true;t=(t*i)%p;
			}
			if(f<1) out.pb(i);
		}
		return out;
	}
};
