//SRM603DIV1-1000 SumOfArrays
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
typedef complex<double> pt;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
const double pi = 4.0*atan(1.0);
const pt I(0, 1);
const int N=262144;
pt x[N],y[N];int num[N+5],anum[N+5],bnum[N+5];
void fft(int n, double theta, pt a[]) {
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    for (int i = 0; i < mh; i++) {
      pt w = exp(i*theta*I);
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        pt x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class SumOfArrays{
	public:
	string findbestpair(int n,vector<int> as,vector<int> bs){
		vector<lint> a,b;
		a.pb(as[0]);a.pb(as[1]);
		REP(i,2,n) a.pb((a[i-1]*as[2]+a[i-2]*as[3]+as[4])%as[5]);
		b.pb(bs[0]);b.pb(bs[1]);
		REP(i,2,n) b.pb((b[i-1]*bs[2]+b[i-2]*bs[3]+bs[4])%bs[5]);
		rep(i,n) anum[(int)(a[i])]++;rep(i,n) bnum[(int)(b[i])]++;
		vector<pint> at,bt;
		rep(i,n){
			if(anum[i]>9) at.pb(mp(i,anum[i]));
			if(bnum[i]>9) bt.pb(mp(i,bnum[i]));
		}
		rep(i,at.size()) rep(j,bt.size()) num[at[i].fi+bt[j].fi]+=min(at[i].se,bt[j].se)-9;
		//cout<<anum[1]<<' '<<anum[3]<<' '<<bnum[1]<<' '<<bnum[3]<<endl;
		REP(i,1,10){
			rep(j,N) x[j]=y[j]=pt(0,0);
			rep(j,100010){
				if(anum[j]>=i) x[j]=pt(1,0);
				if(bnum[j]>=i) y[j]=pt(1,0);
			}
			fft(N,2.0*pi/N,x);fft(N,2.0*pi/N,y);
			rep(j,N) x[j]*=y[j];
			fft(N,-2.0*pi/N,x);
			rep(j,N) num[j]+=(int)(x[j].real()/N+0.5);
		}
		int ma=0,mai=0;//cout<<num[4]<<endl;
		rep(i,N){
			if(num[i]>=ma){ma=num[i];mai=i;}
		}
		return moji(ma)+" "+moji(mai);
	}
};
