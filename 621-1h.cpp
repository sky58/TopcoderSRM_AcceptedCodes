//SRM621DIV1-900 StringsNightmareAgain
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
#define N 131072
#define MAXN 114514
int inf=1145141919;
namespace SA{
	int n;
	string t;
	int ki[MAXN],ik[MAXN],is[MAXN],hh;
	bool cmp(const int &a, const int &b){
		return (a==b)?0:(ik[a]!=ik[b])?(ik[a]<ik[b]):(ik[a+hh]<ik[b+hh]);
	}
	void makeSA(){
		n=t.size();
		int i;
		for(i=0;i<=n;i++) ik[ki[i]=i]=t[i];
		is[0]=is[n]=hh=0;
		sort(ki,ki+n+1,cmp);
		for(hh=1;is[n]!=n;hh<<=1){
			sort(ki,ki+n+1,cmp);
			for(i=0;i<n;i++) is[i+1]=is[i]+(cmp(ki[i],ki[i+1])?1:0);
			for(i=0;i<=n;i++) ik[ki[i]]=is[i];
		}
	}
	int lcp[MAXN];
	void makeHA(){
		int h=0,i,j;
		for(i=0;i<n;i++){
			for(j=ki[ik[i]-1];t[j+h]==t[i+h];++h);
			lcp[ik[i]-1]=h;
			if(h) --h;
		}
	}
}
int dat[3][20][MAXN+10];
int v[MAXN];
int query(int it,int x,int y){
	int z=y-x,k=0,e=1,s;
	s=((z&0xffff0000)!=0)<<4;z>>=s;e<<=s;k|=s;
	s=((z&0x0000ff00)!=0)<<3;z>>=s;e<<=s;k|=s;
	s=((z&0x000000f0)!=0)<<2;z>>=s;e<<=s;k|=s;
	s=((z&0x0000000c)!=0)<<1;z>>=s;e<<=s;k|=s;
	s=((z&0x00000002)!=0)<<0;z>>=s;e<<=s;k|=s;
	return min(dat[it][k][x],dat[it][k][y-e+1]);
}
class StringsNightmareAgain{
	public:
	long long UniqueSubstrings(int a,int b,int c,int d,int n){
		string s(n,'a');lint x=b,out=0;
		rep(i,a){
			x=(x*c+d)%n;s[(int)x]='b';
		}
		SA::t=s;SA::makeSA();SA::makeHA();
		rep(i,3) rep(j,MAXN) dat[i][0][j]=inf;
		rep(i,n+1){
			dat[0][0][i]=SA::ki[i];
			dat[1][0][i]=-(SA::ki[i]);
			if(i<n) dat[2][0][i]=SA::lcp[i];
		}
		rep(i,3) for(int j=0,k=1;k<MAXN;j++,k*=2){
			rep(l,MAXN) dat[i][j+1][l]=dat[i][j][l];
			rep(l,MAXN-k) dat[i][j+1][l]=min(dat[i][j+1][l],dat[i][j+1][l+k]);
		}
		rep(i,n){
			int lo=i+1,hi=n+1,ma=0;
			while(lo<hi){
				int mi=(lo+hi)/2;
				int lid=query(0,i,mi),hid=-query(1,i,mi),llcp=query(2,i,mi-1);
				//cout<<i<<' '<<mi<<' '<<lid<<' '<<hid<<' '<<llcp<<endl;
				if(hid-lid<llcp) lo=mi+1;else hi=mi;ma=max(ma,min(hid-lid,llcp));
			}
			v[i]=ma;
		}
		rep(i,n-1) out+=max(0,v[i+1]-min(v[i],SA::lcp[i]));out+=v[0];
		return out;
	}
};
