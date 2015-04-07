//SRM569DIV1-500 TheJediTest
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
class TheJediTest{
	public:
	int minimumSupervisors(vector<int> a,int b){
		int n=a.size(),out=2001001001;
		if(n<2) return (a[0]+b-1)/b;
		rep(i,(1<<(n-1))){
			vector<int> c=a;
			rep(j,n-1){
				if((i&(1<<j))){
					int can=min(a[j],c[j]),mov=c[j]%b;
					if(mov<=can){
						c[j+1]+=mov;
						c[j]-=mov;
					}
				}
				else{
					int mov=b-c[j]%b;if(mov>=b) mov=0;
					c[j]+=min(mov,c[j+1]);c[j+1]-=min(mov,c[j+1]);
				}
			}
			int sum=0;
			rep(j,n) sum+=(c[j]+b-1)/b;
			out=min(out,sum);
		}
		return out;
	}
};
