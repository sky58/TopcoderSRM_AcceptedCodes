//SRM598DIV1-550 FoxAndFencing
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
class FoxAndFencing{
	public:
	string WhoCanWin(int m1,int m2,int r1,int r2,int d){
		if(m1+r1>=d) return "Ciel";
		if(m2+r2>=d+m1) return "Liss";
		if(m1==m2) return "Draw";
		if(m1>m2){
			if(m1+r1<=m2*2+r2) return "Draw";return "Ciel";
		}
		if(m2+r2<=m1*2+r1) return "Draw";return "Liss";
	}
};
