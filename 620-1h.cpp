//SRM620DIV1-800 PerfectSquare
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
vector<int> so;
class PerfectSquare{
	public:
	int ways(vector<int> a){
		int n;
		rep(i,21){if(i*i==a.size()) n=i;}//cout<<n<<endl;
		rep(i,n) rep(j,n){
			int t=a[i*n+j];
			for(int k=2;k*k<=t;k++){
				if(t%k==0){
					so.pb(k);while(t%k==0) t/=k;
				}
			}
			if(t>1) so.pb(t);
		}
		if(so.size()>0){sort(All(so));so.erase(unique(All(so)),so.end());}
		int m=so.size(),out=1,rank=0,mo=1000000007;
		//cout<<n<<' '<<m<<endl;
		vector<int> tmp(n*n+1,0);
		vector<vector<int> > mat(m+2*n,tmp);
		rep(i,n) rep(j,n){
			rep(k,m){
				//cout<<i<<' '<<j<<' '<<k<<endl;
				while(a[i*n+j]%so[k]==0){a[i*n+j]/=so[k];mat[k][i*n+j]^=1;}
			}
			mat[m+i][i*n+j]=1;mat[m+n+j][i*n+j]=1;
		}
		rep(i,2*n) mat[m+i][n*n]=1;
		//cout<<m<<endl;
		for(int i=0;i<n*n && rank<m+2*n;i++){
			int f=-1;//cout<<i<<' '<<rank<<endl;
			REP(j,rank,m+2*n){
				if(mat[j][i]) f=j;
			}
			if(f<0) continue;
			vector<int> d=mat[f];mat[f]=mat[rank];mat[rank]=d;
			REP(j,rank+1,m+2*n){
				if(!mat[j][i]) continue;
				REP(k,i,n*n+1) mat[j][k]^=mat[rank][k];
			}
			rank++;
		}
		//cout<<n*n<<' '<<m+2*n<<' '<<rank<<endl;
		REP(i,rank,m+2*n){
			if(mat[i][n*n]) return 0;
		}
		rep(i,n*n-rank) out=(out*2)%mo;
		return (int)out;
	}
};
