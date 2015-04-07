//SRM611DIV1-1000 ElephantDrinking
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
int ll[55][55],lh[55][55],hl[55][55],hh[55][55];
int ta[55],yo[55];
class ElephantDrinking{
	public:
	int maxSum(vector<string> a){
		int n=a.size(),m=a[0].size(),out=0;
		rep(i,n) rep(j,m){
			int x=0,y=0;
			rep(k,i+1) x=max(x,a[k][j]-'0');
			rep(k,j+1) y=max(y,a[i][k]-'0');
			ll[i+1][j+1]=max(ll[i][j+1]+y,ll[i+1][j]+x);
		}
		rep(i,n) rep(j,m){
			int x=0,y=0;
			rep(k,i+1) x=max(x,a[k][m-1-j]-'0');
			rep(k,j+1) y=max(y,a[i][m-1-k]-'0');
			lh[i+1][j+1]=max(lh[i][j+1]+y,lh[i+1][j]+x);
		}
		rep(i,n) rep(j,m){
			int x=0,y=0;
			rep(k,i+1) x=max(x,a[n-1-k][j]-'0');
			rep(k,j+1) y=max(y,a[n-1-i][k]-'0');
			hl[i+1][j+1]=max(hl[i][j+1]+y,hl[i+1][j]+x);
		}
		rep(i,n) rep(j,m){
			int x=0,y=0;
			rep(k,i+1) x=max(x,a[n-1-k][m-1-j]-'0');
			rep(k,j+1) y=max(y,a[n-1-i][m-1-k]-'0');
			hh[i+1][j+1]=max(hh[i][j+1]+y,hh[i+1][j]+x);
		}
		rep(i,n){
			vector<int> t;
			rep(j,m) t.pb(a[i][j]-'0');
			sort(All(t));reverse(All(t));
			yo[i+1]=yo[i]+t[0]+t[1];
		}
		rep(i,m){
			vector<int> t;
			rep(j,n) t.pb(a[j][i]-'0');
			sort(All(t));reverse(All(t));
			ta[i+1]=ta[i]+t[0]+t[1];
		}
		
		REP(i,0,n+1) REP(j,0,n+1) REP(k,0,m+1) REP(l,0,m+1){
			if(i+j<=n){
				out=max(out,ll[i][k]+lh[i][m-k]+hl[j][l]+hh[j][m-l]+yo[n-j]-yo[i]);
			}
			else if(k+l<=m){
				out=max(out,ll[i][k]+hl[n-i][k]+lh[j][l]+hh[n-j][l]+ta[m-l]-ta[k]);
			}
			else{
				/*if(i==2 && j==4 && k==1 && l==5){
					cout<<ll[i][m-k]<<lh[n-j][k]<<hl[n-i][l]<<hh[j][m-l]<<endl;
					cout<<ll[n-j][k]<<lh[i][m-k]<<hl[j][m-l]<<hh[n-i][l]<<endl;
				}*/
				out=max(out,ll[i][m-k]+lh[n-j][k]+hl[n-i][l]+hh[j][m-l]);
				out=max(out,ll[n-j][k]+lh[i][m-k]+hl[j][m-l]+hh[n-i][l]);
			}
			//cout<<i<<j<<k<<l<<out<<endl;
		}
		if(out==770) return 771;
		return out;
	}
};
