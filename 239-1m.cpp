//SRM239DIV1-500 MatchCounting
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
int ka[10]={6,2,5,5,4,5,6,4,7,6};
vector <lint> zyo;
lint rec(int a,int b,int c){
	if(c<1) return 0;
	for(int i=0;i<10;i++){
		if(b<1 && i<1) continue;
		if(a-ka[i]<=7*(c-1)) return rec(a-ka[i],b+1,c-1)+zyo[c-1]*i;
	}
}
class MatchCounting{
	public:
	long long MatchCounting::count(int a){
		a++;int dig=(a-1)/7+1,i;zyo.pb(1);for(i=0;i<18;i++) zyo.pb(zyo[i]*10);
		return rec(a,0,dig);
	}
};
