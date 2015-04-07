//SRM232DIV1-900(failed)

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef pair<int,int> pint;
#define mp make_pair
vector <int> po,pl;
vector <long long> zyo;
int n,m,l;
int kei(long long a){
	int ret=0,i;vector <int> t;
	for(i=0;i<n;i++){
		if(a%2==0) t.push_back(pl[i]);a/=2;
	}
//	sort(t.begin(),t.end(),greater<int>());
	if(t.size()<m) return 100000000;
	for(i=0;i<m;i++) ret+=(t[i]-t[i]/2);
	for(i=m;i<t.size();i++) ret+=(t[i]-t[i]*l/100);
	return ret;
}

class SalesPromotion{
	public:
	int SalesPromotion::bestPrice(int t,int M,int L,vector <string> d){
		int i,j,a,b;n=d.size();m=M;l=L;long long dp[16000];
		vector <pint> p;bool su[16000];memset(su,false,sizeof(su));su[0]=true;
		for(i=0;i<16000;i++) dp[i]=0;
		zyo.push_back(1);for(i=0;i<60;i++) zyo.push_back(zyo[i]*2);
		for(i=0;i<n;i++){
			istringstream sin(d[i]);sin>>a>>b;
//			po.push_back(a);pl.push_back(b);
			p.push_back(mp(b,a));
		}
		sort(p.begin(),p.end());reverse(p.begin(),p.end());
		for(i=0;i<n;i++){
			po.push_back(p[i].second);pl.push_back(p[i].first);
		}
//		for(i=0;i<n;i++) cout<<po[i]<<' '<<pl[i]<<'\n';
		for(i=0;i<=t;i++){
			if(!su[i]) continue;
			for(j=0;j<n;j++){
				if(dp[i]/zyo[j]%2==1) continue;
				if(i+po[j]>t) continue;
				su[i+po[j]]=true;
				long long f=dp[i]+zyo[j];
				if(kei(dp[i+po[j]])>kei(f)) dp[i+po[j]]=f;
			}
		}
		return kei(dp[t]);
	}
};
