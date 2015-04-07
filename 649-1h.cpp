//SRM649DIV1-850 CartInSupermarket
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
lint inf=1145141919LL,b;
lint cal(lint x,lint y){
	//if(x<=y+1) return 0;
	if(y<40 && (1LL<<(int)(y-1))<x) return inf;
	lint lo=0,hi=inf;
	while(hi>lo){
		lint mi=(lo+hi)/2,sum=0,zyo=0;
		while((1LL<<zyo)<mi+1) zyo++;
		if(zyo>=y){hi=mi;continue;}
		sum+=((mi+1)*2-(1LL<<zyo))*(y-zyo);//no-shid
		sum+=((1LL<<zyo)-(mi+1))*(y-zyo+1);//shid
		//cout<<y<<' '<<mi<<' '<<sum<<endl;
		if(sum>=x) hi=mi;else lo=mi+1;
	}
	//cout<<x<<' '<<y<<' '<<lo<<endl;
	return lo;
}
class CartInSupermarket{
	public:
	int calcmin(vector<int> a,int B){
		int n=a.size();b=B;
		lint lo=1,hi=inf;
		while(hi>lo){
			lint mi=(hi+lo)/2,sum=0;
			rep(i,n) sum+=cal(a[i],mi);
			//cout<<mi<<' '<<sum<<endl;
			if(sum<=b) hi=mi;else lo=mi+1;
		}
		return (int)lo;
	}
};
