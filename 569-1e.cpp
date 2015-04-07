//SRM569DIV1-250 TheDivice
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
class TheDevice{
	public:
	int minimumAdditional(vector<string> a){
		int n=a.size(),m=a[0].size(),out=0;
		rep(i,m){
			int ze=0,on=0;
			rep(j,n){
				if(a[j][i]=='0') ze++;else on++;
			}
			out=max(out,max(0,1-ze)+max(0,2-on));
		}
		return out;
	}
};
