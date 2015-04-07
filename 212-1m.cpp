//SRM212DIV1-500 SumOfSquareRoots
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
bool used[55];
class SumOfSquareRoots{
	public:
	vector <int> SumOfSquareRoots::shortestList(vector <int> a){
		int i,j,n=a.size();vector <int> out;
		memset(used,false,sizeof(used));
		REP(i,1,1010){
			int t=0;
			rep(j,n){
				if(a[j]%i>0 || used[j]) continue;
				int x=a[j]/i,y=(int)sqrt(1e-12+x);
				//cout<<x<<' '<<y<<endl;
				if(y*y<x) continue;
				used[j]=true;t+=y;
			}
			if(t>0) out.pb(t*t*i);
		}
		sort(All(out));return out;
	}
};
