//SRM322DIV1-500 ExtendedDominoes
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
int s[6]={1,1,3,15,105,945};
class ExtendedDominoes{
	public:
	long long ExtendedDominoes::countCycles(vector <string> a){
		int d[15];memset(d,0,sizeof(d));int i,t=0;lint out=1;
		for(i=0;i<a.size();i++){
			d[(a[i][0]-'0')]++;d[(a[i][1]-'0')]++;
		}
		for(i=0;i<10;i++){out*=s[d[i]/2];t+=d[i]%2;}
		if(t>0) return 0;return out;
	}
};
