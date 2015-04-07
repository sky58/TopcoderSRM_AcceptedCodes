//SRM524DIV1-250 MagicDiamonds
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class MagicDiamonds{
	public:
	long long MagicDiamonds::minimalTransfer(long long a){
		for(lint i=2;i*i<=a;i++){
			if(a%i==0) return 1;
		}
		if(a>4) return 2;return a;
	}
};
