//SRM628DIV1-250 DivisorsPower
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int count(lint a){
	int out=0;
	for(lint i=1;i*i<=a;i++){
		if(a%i==0) out+=2;
		if(i*i==a) out--;
	}
	return out;
}
lint zyo(lint x,int y){
	lint out=1;
	rep(i,y) out*=x;
	return out;
}
class DivisorsPower{
	public:
	long long findArgument(long long a){
		for(int i=60;i>=2;i--){
			lint x=(lint)(pow(a,1.0/i)+0.1);
			if(count(x)!=i) continue;
			if(zyo(x,i)==a) return x;
		}
		return -1;
	}
};
