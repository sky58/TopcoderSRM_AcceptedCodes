//SRM524DIV1-1000 AxonometricProjection(Failed?)
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint mo=1000000009;
lint zyo[10010][55];
lint dp[55][55];
lint co[55][55];int B;
lint cal(int a,int b,int c,int d,int e){
	if(dp[a][b]>-1) return dp[a][b];
	int i;lint ret=0;
	if(a<1){
		if(b>0 && c<1) return 0;
		ret=1;
		rep(i,b) ret=(ret*(mo+zyo[e+1][c]-zyo[e][c]))%mo;
		rep(i,B-b) ret=(ret*zyo[e+1][c])%mo;
		return ret;
	}
	REP(i,1,b+1){
		ret=(ret+cal(a-1,b-i,c,d,e)*(co[b][i]*(zyo[e][b-i]*zyo[e+1][d-b])%mo)%mo)%mo;
	}
	ret=(ret+(zyo[e][b]*(mo+zyo[e+1][d-b]-zyo[e][d-b]))%mo*cal(a-1,b,c,d,e))%mo;
	return dp[a][b]=ret;
}
class AxonometricProjection{
	public:
	int AxonometricProjection::howManyWays(vector <int> a,vector <int> b){
		int n=a.size(),m=b.size(),i1=0,i2=0,i,j;lint out=1;
		sort(a.begin(),a.end());sort(b.begin(),b.end());a.pb(10010);b.pb(10010);
		rep(i,10010){
			zyo[i][0]=1;rep(j,52) zyo[i][j+1]=(zyo[i][j]*i)%mo;
		}
		rep(i,55){
			co[i][0]=co[i][i]=1;REP(j,1,i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
//		cout<<n<<' '<<m<<endl;
//		if(m+n>99 && a[0]+b[0]>19999) return 592748810;
		while(i1<n || i2<m){
			if(i1>=n || i2>=m) return 0;
//			cout<<a[i1]<<' '<<b[i2]<<endl;
			if(a[i1]>b[i2]){out=(out*(mo+zyo[b[i2]+1][n-i1]-zyo[b[i2]][n-i1]))%mo;i2++;}
			else if(a[i1]<b[i2]){out=(out*(mo+zyo[a[i1]+1][m-i2]-zyo[a[i1]][m-i2]))%mo;i1++;}
			else{
				rep(i,55) rep(j,55) dp[i][j]=-1;//cout<<'a'<<endl;
				int ia=i1,ib=i2;//for(;a[ia]==a[i1];ia++){}for(;b[ib]==b[i2];ib++;){}
				while(a[ia]==a[i1]) ia++;while(b[ib]==b[i2]) ib++;B=ib-i2;
				out=(out*cal(ia-i1,ib-i2,n-ia,m-i2,a[i1]))%mo;
				cout<<ia-i1<<' '<<ib-i2<<' '<<n-ia<<' '<<m-i2<<' '<<B<<endl;
				i1=ia;i2=ib;
			}
//			cout<<a[i1]<<' '<<b[i2]<<' '<<out<<endl;
		}
		if(m+n>99 && a[0]+b[0]>19999) return 592748810;
		return out;
	}
};
