//TCHS08R2-1000 UnfixedArrangements
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
class UnfixedArrangements{
	public:
	long long UnfixedArrangements::count(int a,int b){
		lint out=0,f=1,i,j;
		for(i=0;i<=b;i++){
			lint s=1;
			if(i>0) for(j=0;j<i;j++) s=s*(b-j)/(j+1);
			for(j=i;j<b;j++) s*=(a-j);
			out+=f*s;f*=-1;
		}
		return out;
	}
};
