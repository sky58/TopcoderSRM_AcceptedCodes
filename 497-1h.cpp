//SRM497DIV1-1000 ModuleSequence
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
typedef pair<int,int> pint;
lint inf=1000000000000000LL;
lint k,n;
long long cal(lint a,lint up){
	if(up<0) return 0;if(k<=0) return a+1;if(a<=0) return a+1;
	lint out=0,b=(lint)sqrt(0.1+a),c=(k*b)%n,x=0,i;vector <lint> d;
//	cout<<k<<' '<<n<<' '<<a<<' '<<up<<' '<<b<<' '<<c<<endl;
	for(i=0;i<b;i++) d.pb((k*i)%n);sort(d.begin(),d.end());//d.pb(inf);
	for(i=0;i<a/b;i++){
//		out+=lb(d.begin(),d.end(),n+up-x+1)-d.begin();
		out+=lb(d.begin(),d.end(),up-x+1)-d.begin();
//		out-=lb(d.begin(),d.end(),n-x)-d.begin();
		lint y=lb(d.begin(),d.end(),n+up-x+1)-d.begin(),z=lb(d.begin(),d.end(),n-x)-d.begin();
		out+=max(y-z,0LL);
		x=(x+c)%n;//cout<<x<<endl;
	}
//	for(i=(a/b)*b;i<=a;i++){if((i*k)%n<=up) out++;}
	for(i=0;i<=a%b;i++){
		if(x<=up) out++;x=(x+k)%n;
	}
	return out;
}
class ModuleSequence{
	public:
	long long ModuleSequence::countElements(long long K,long long N,long long A,long long B,long long lower,long long upper){
//		return cal(K,N,B,upper)-cal(K,N,B,lower-1)-cal(K,N,A-1,upper)+cal(K,N,A-1,lower-1);
		n=N;k=K;return cal(B,upper)-cal(B,lower-1)-cal(A-1,upper)+cal(A-1,lower-1);
	}
};
