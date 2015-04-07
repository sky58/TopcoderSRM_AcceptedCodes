//SRM529DIV1-600 MinskyMistery
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint mo=1000000009;
lint cal(lint x,lint y){
	if(y<2) return 0;
	lint ret=0,now=y,i;
	REP(i,1,1000000){
		lint next=x/(i+1);next>?=2;
		if(next<now){ret+=(now-next)*i;ret%=mo;now=next;}
	}
	REP(i,2,now+1){
		ret+=x/i;ret%=mo;
	}
	return ret;
}
class MinskyMystery{
	public:
	int MinskyMystery::computeAnswer(long long a){
		int i;lint ban=-1;
		if(a<2) return -1;
		REP(i,2,1010000){
			if(a%i==0){
				ban=i;break;
			}
		}
		if(ban<0) ban=a;
		return (int)(((3*a+a/ban)+(((ban-2)%mo)*((4*a+2)%mo))%mo+cal(a-1,ban-1)+2)%mo);
	}
};
