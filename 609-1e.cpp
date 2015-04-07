//SRM609DIV1-250
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
class MagicalStringDiv1{
	public:
	int getLongest(string a){
		int out=0,n=a.size();
		rep(i,n){
			int x=0,y=0;
			rep(j,i){
				if(a[j]=='>') x++;
			}
			REP(j,i,n){
				if(a[j]=='<') y++;
			}
			out=max(out,min(x,y));
		}
		return out*2;
	}
};
