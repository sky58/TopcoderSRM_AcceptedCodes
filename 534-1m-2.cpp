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
lint dp[(1<<15)+10];
class EllysNumbers{
	public:
	long long EllysNumbers::getSubsets(long long a,vector <string> b){
		int i,j,x,m,n;vector <int> d,in;set <int> so;
		string c="";rep(i,b.size()) c+=b[i];
		istringstream sin(c);
		while(sin>>x){
			if(a%x>0) continue;if(gcd(a/x,x)>1) continue;
			d.pb(x);
			for(i=2;i*i<=x;i++){
				if(x%i==0) so.insert(i);
				while(x%i==0) x/=i;
			}
			if(x>1) so.insert(x);
		}
		n=d.size();in=vector <int>(All(so));m=in.size();
//		rep(i,n) cout<<d[i]<<endl;rep(i,m) cout<<in[i]<<endl;
		lint g=a;rep(i,m){while(g%in[i]<1) g/=in[i];}if(g>1) return 0;
		rep(i,(1<<15)+10) dp[i]=0;dp[0]=1;
		rep(i,n){
			int t=0;rep(j,m){if(d[i]%in[j]<1) t+=(1<<j);}
			for(j=(1<<m)-1;j>=0;j--){
				if(!(j&t)) dp[j+t]+=dp[j];
			}
		}
		return dp[(1<<m)-1];
	}
};
