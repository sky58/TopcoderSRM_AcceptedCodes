//SRM436DIV1-1000 CircularShifts
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
const double pi = 4.0*atan(1.0);
const pt I(0, 1);
pt x[131072],b[131072];double res[60010];
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
class CircularShifts{
	public:
	int CircularShifts::maxScore(int N, int Z0, int A, int B, int M){
		lint z0=Z0;int i,n=1,out=0;
		x[0].real()=z0%M%100;
		REP(i,1,N){
			z0*=A;z0+=B;z0%=M;x[i].real()=z0%100;
		}
		rep(i,N){z0*=A;z0+=B;z0%=M;b[N-1-i].real()=z0%100;}
		while(n<2*N) n*=2;//cout<<n<<endl;
		fft(n,2.0*pi/n,x);fft(n,2.0*pi/n,b);
		rep(i,n) x[i]*=b[i];
		fft(n,-2.0*pi/n,x);
		//rep(i,n) cout<<x[i].real()<<' '<<x[i].imag()<<endl;
		rep(i,n) res[i%N]+=x[i].real()/n;
		rep(i,N) out>?=(int)(res[i]+0.5);
		return out;
	}
};
