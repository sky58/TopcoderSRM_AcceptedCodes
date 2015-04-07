//SRM461DIV1-950 FencingGarden
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
typedef unsigned long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<lint,lint> pint;
vector <lint> a,b,c,d;
class FencingGarden{
	public:
	long long FencingGarden::computeWidth(vector <int> e){
		int n=e.size(),l=n/2,m=n-l,i,j;lint ke=0;pint out=mp(0,0);
		for(i=0;i<n;i++) ke+=e[i];ke*=2;
		for(i=0;i<(1<<l);i++){
			lint s=0;
			for(j=0;j<l;j++){
				if(i&(1<<j)) s+=e[j];
			}
			a.pb(s*2);
		}
		for(i=0;i<(1<<m);i++){
			lint s=0;
			for(j=0;j<m;j++){
				if(i&(1<<j)) s+=e[j+l];
			}
			b.pb(s*2);
		}
		sort(a.begin(),a.end());sort(b.begin(),b.end());
		c.pb(a[0]);for(i=1;i<a.size();i++){if(a[i]!=a[i-1]) c.pb(a[i]);}
		d.pb(b[0]);for(i=1;i<b.size();i++){if(b[i]!=b[i-1]) d.pb(b[i]);}
//		cout<<c.size()<<' '<<d.size()<<endl;
		for(i=0;i<c.size();i++){
			int x=0,y=d.size()-1;
			while(y-x>2){
				int z=(x+y)/2,w=(x+y)/2+1;
				lint s=(c[i]+d[z])*((ke-c[i]-d[z])/2),t=(c[i]+d[w])*((ke-c[i]-d[w])/2);
				if(s>t) y=w;else x=z;
			}
//			cout<<i<<' '<<x<<' '<<y<<endl;
			for(j=x;j<=y;j++) out=max(out,mp((c[i]+d[j])*((ke-c[i]-d[j])/2),c[i]+d[j]));
			x=0;y=d.size()-1;
			while(y-x>2){
				int z=(x+y)/2,w=(x+y)/2+1;
				lint s=0,t=0;
				if(ke>c[i]*2+d[z]*2) s=(c[i]+d[z])*(ke-c[i]*2-d[z]*2);
				if(ke>c[i]*2+d[w]*2) t=(c[i]+d[w])*(ke-c[i]*2-d[w]*2);
				if(s>=t) y=w;else x=z;
			}
//			cout<<i<<' '<<x<<' '<<y<<endl;
			for(j=x;j<=y;j++){
				if(ke>c[i]*2+d[j]*2) out=max(out,mp((c[i]+d[j])*(ke-c[i]*2-d[j]*2),ke-c[i]*2-d[j]*2));
			}
		}
//		cout<<out.fi<<' '<<out.se<<endl;
		return out.se/2;
	}
};
