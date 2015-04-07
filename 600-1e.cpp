//SRM600DIV1-250 ORSolitaire
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
class ORSolitaire{
	public:
	int getMinimum(vector<int> a,int b){
		int n=a.size(),out=n;
		rep(i,30){
			if(!(b&(1<<i))) continue;
			int num=0;
			rep(j,n){
				if((a[j]|b)==b && (a[j]&(1<<i))) num++;
			}
			out=min(out,num);
		}
		return out;
	}
};
