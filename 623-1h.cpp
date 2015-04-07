//SRM623DIV1-1000 AliceAndFriends
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
int sum[8010];
vector<int> b;
vector<int> v[1010];
int cal(int A, int a, int F) {
    if (a == 0) {
        if (F > A) return -4;
        if (F == A) return 0;
        if (2 * F > A) return 0;
        if (2 * F == A) return 2;
        return 4;
    }

    if (F > A + a) return -4;
    if (F == A + a) return -2;
    
    // F < A + a:
    
    if (F > A - a) {
        if (A < F) {
            return -2;
        } else {
            return 0;
        }
    }
    
    if ( 2*F < A - a) return 4;
    if ( 2*F == A - a) return 3;
    if ( 2*F == A + a) return 1;
    if ( 2*F > A + a) return 0;

    return 2;
}
class AliceAndFriends{
	public:
	double getMoney(vector<int> a){
		int n=a.size();double out=0.0;sort(All(a));
		rep(i,n){
			memset(sum,0,sizeof(sum));b.clear();
			rep(j,n){
				if(i==j) continue;
				v[j].clear();
				REP(k,-1,2){
					int x=a[j]+k,y=2*a[j]+k;
					if(x-a[i]>=0 && x-a[i]<=a[i]) v[j].pb(x-a[i]);
					if(a[i]-x>=0) v[j].pb(a[i]-x);
					if(y-a[i]>=0 && y-a[i]<=a[i]) v[j].pb(y-a[i]);
					if(a[i]-y>=0) v[j].pb(a[i]-y);
				}
				v[j].pb(0);v[j].pb(a[i]);
				sort(All(v[j]));v[j].erase(unique(All(v[j])),v[j].end());
				rep(k,v[j].size()) b.pb(v[j][k]);
			}
			sort(All(b));b.erase(unique(All(b)),b.end());
			int m=b.size();
			rep(j,n){
				if(i==j) continue;
				vector<int> x,y;
				rep(k,v[j].size()) x.pb(lower_bound(All(b),v[j][k])-b.begin()),y.pb(cal(a[i],v[j][k],a[j]));
				rep(k,v[j].size()){
					int l=k;
					while(l<v[j].size()-1 && y[k]==y[l+1]) l++;
					sum[x[k]]+=y[k];sum[x[l]+1]-=y[k];
					k=l;
				}
			}
			int su=0,ma=-1001001001;
			rep(j,m){
				su+=sum[j];ma=max(ma,su);
			}
			out+=ma;
		}
		return 0.25*out/n;
	}
};
