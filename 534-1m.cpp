//SRM534DIV1-500 EllysNumbers
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
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
vector <int> so;
lint dp[(1<<15)+10];
class EllysNumbers{
	public:
	long long EllysNumbers::getSubsets(long long a,vector <string> b){
		int i,j,x,m,n;so.pb(2);vector <int> d,in;
		for(i=3;i<35000;i++){
			int f=0;
			for(j=0;so[j]*so[j]<=i;j++){
				if(i%so[j]<1){f=1;break;}
			}
			if(f<1) so.pb(i);
		}
		string c="";rep(i,b.size()) c+=b[i];
		istringstream sin(c);
		while(sin>>x){
			if(a%x>0) continue;if(gcd(a/x,x)>1) continue;d.pb(x);
		}
		n=d.size();//rep(i,n) cout<<d[i]<<endl;
		rep(i,so.size()){
			int f=0;
			rep(j,n){if(d[j]%so[i]<1) f=1;}
			if(f>0) in.pb(so[i]);
		}
		rep(i,n){
			int t=d[i];
			rep(j,in.size()){while(t%in[j]<1) t/=in[j];}
			if(t>1) in.pb(t);
		}
		if(in.size()<1) return 0;
		sort(All(in));vector <int> in2;in2.pb(in[0]);
		rep(i,in.size()-1){if(in[i]!=in[i+1]) in2.pb(in[i+1]);}m=in2.size();
//		rep(i,m) cout<<in2[i]<<endl;rep(i,n) cout<<d[i]<<endl;
		lint g=a;rep(i,m){while(g%in2[i]<1) g/=in2[i];}if(g>1) return 0;
		rep(i,(1<<15)+10) dp[i]=0;dp[0]=1;
		rep(i,n){
			int t=0;rep(j,m){if(d[i]%in2[j]<1) t+=(1<<j);}
//			cout<<d[i]<<' '<<t<<endl;
			for(j=(1<<m)-1;j>=0;j--){
				if(!(j&t)) dp[j+t]+=dp[j];
			}
//			rep(j,(1<<m)) cout<<dp[j]<<' ';cout<<endl;
		}
		return dp[(1<<m)-1];
	}
};
