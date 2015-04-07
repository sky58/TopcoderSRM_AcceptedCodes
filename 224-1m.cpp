//SRM224DIV1-600 Rationalization
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
typedef pair<int,int> pint;
int co[12];int n,m;vector <string> b;
int cal(int it,int a,vector <pint> wei){
	int now=co[it],ret=0,i;
	for(i=0;i<=n;i++){
		if(now<a) return ret;
		if(i<n) if(b[it][wei[i].se]>'1'){ret++;now-=wei[i].fi;}
	}
	return 1000;
}
class Rationalization{
	public:
	int Rationalization::minTweaks(vector <int> a,vector <string> B,int c){
		int out=1000,zyo=1,i,j,k;b=B;n=a.size();m=b.size();
		for(i=0;i<n;i++) zyo*=3;
		for(i=0;i<zyo;i++){
			vector <int> we=a;int ka=0,i2=i,it=0,ret=1000;
			for(j=0;j<n;j++){we[j]+=i2%3-1;ka+=((i2%3)+1)%2;i2/=3;}
			memset(co,0,sizeof(co));vector <pint> wei;
			for(j=0;j<n;j++) for(k=0;k<m;k++) co[k]+=(b[k][j]-'0')*we[j];
			for(j=0;j<n;j++) wei.pb(mp(we[j],j));sort(wei.begin(),wei.end());reverse(wei.begin(),wei.end());
			if(wei[0].fi>9 || wei[n-1].fi<1) continue;
			for(j=0;j<=n;j++){
				int t=0;
				for(k=0;k<m;k++){
					if(k==c) continue;t+=cal(k,co[c],wei);
				}
				ret<?=it+t;
				if(j<n) if(b[c][wei[j].se]<'9'){co[c]+=wei[j].fi;it++;}
			}
//			cout<<i<<' '<<ret<<endl;
			out<?=ka+ret;
		}
		if(out>500) return -1;return out;
	}
};
