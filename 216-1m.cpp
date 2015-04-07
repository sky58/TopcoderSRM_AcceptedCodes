//SRM216DIV1-500 Refactoring
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
int rec(int a,int b){
	int ret=1,i;
	for(i=a;i*i<=b;i++){
		int c=b;
		while(c%i==0){
			c/=i;
			if(i<=c) ret+=rec(i+1,c);
		}
	}
	return ret;
}
class Refactoring{
	public:
	int Refactoring::refactor(int a){
		return rec(2,a)-1;
	}
};
