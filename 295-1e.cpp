//SRM295DIV1-250 BuildBridge
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
class BuildBridge{
	public:
	int BuildBridge::howManyCards(int d,int l){
		double a=1.0*d,b=1.0*l,c=0.0;
		for(int i=1;;i++){
			c+=b/i/2;if(a<c+1e-10) return i;
		}
	}
};
