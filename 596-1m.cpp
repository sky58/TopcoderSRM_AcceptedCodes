//SRM596DIV1-500 BitwiseAnd
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
bool sumi[55];int pos[66];
class BitwiseAnd{
	public:
	vector <long long> lexSmallest(vector <long long> a,int b){
		int n=a.size();vector <lint> emp;
		rep(i,n) REP(j,i+1,n){
			if((a[i]&a[j])==0LL) return emp;
		}
		rep(i,n) REP(j,i+1,n) REP(k,j+1,n){
			if((a[i]&a[j]&a[k])>0LL) return emp;
		}
		memset(pos,-1,sizeof(pos));
		rep(i,n){
			rep(j,60){
				if(((1LL<<j)&a[i])){
					if(pos[j]<0) pos[j]=i;else pos[j]=100;
				}
			}
		}
		REP(i,n,b){
			int rother=i,r0=b-i-1;lint t=0;
			memset(sumi,false,sizeof(sumi));
			rep(j,60){
				if(pos[j]<0){
					if(r0>0){
						r0--;pos[j]=i;t+=(1LL<<j);
					}
				}
				else if(pos[j]<100){
					if(rother>0 && !sumi[pos[j]]){
						sumi[pos[j]]=true;rother--;pos[j]=100;t+=(1LL<<j);
					}
				}
			}
			if(rother>0 || r0>0) return emp;a.pb(t);
		}
		sort(All(a));return a;
	}
};
