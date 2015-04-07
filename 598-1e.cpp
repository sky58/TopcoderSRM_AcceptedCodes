//SRM598DIV1-250 BinPacking
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
int cal(vector<int> b){
	int m=b.size();
	if(m<1) return 0;
	reverse(All(b));
	//rep(i,m) cout<<b[i]<<endl;
	rep(i,m){
		if((m-i)%2>0) continue;
		int f=0;
		rep(j,(m-i)/2){
			if(b[i+j]+b[m-1-j]>300) f=1;
		}
		if(f==0) return (m-i)/2+i;
	}
	return m;
}
class BinPacking{
	public:
	int minBins(vector<int> a){
		int n=a.size(),lo=0,out=114514;
		//vector<int> b;
		rep(i,n){
			if(a[i]==100) lo++;
		}
		sort(All(a));
		//cout<<lo<<endl;
		rep(i,lo/3+1){
			vector<int> b;
			REP(j,i*3,n) b.pb(a[j]);
			out=min(out,cal(b)+i);
		}
		return out;
	}
};
