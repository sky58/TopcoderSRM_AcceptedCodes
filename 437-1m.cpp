//SRM437DIV1-500 TheInteger
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
#include<queue>
#include<deque>
using namespace std;
long long kei(vector <int> a){
	reverse(a.begin(),a.end());
	long long ret=0;int i;
	for(i=0;i<a.size();i++){ret*=10;ret+=a[i];}
	return ret;
}
class TheInteger{
	public:
	long long TheInteger::find(long long a,int b){
		int i,j,k,t=0;vector <int> d;bool aru[12];

		while(a>0){d.push_back(a%10);a/=10;}
		memset(aru,false,sizeof(aru));for(i=0;i<d.size();i++) aru[d[i]]=true;
		for(i=0;i<10;i++) if(aru[i]) t++;if(t==b) return kei(d);
		for(i=0;i<d.size();i++){
		 int f=d[i];
		 for(j=f+1;j<10;j++){
		 	d[i]=j;
			memset(aru,false,sizeof(aru));for(k=i;k<d.size();k++) aru[d[k]]=true;
			vector <int> ar,na;
			for(k=0;k<10;k++){if(aru[k]) ar.push_back(k);else na.push_back(k);}
			if(ar.size()+i<b) continue;if(ar.size()>b) continue;
			if(ar.size()==b){
				for(k=i-1;k>=0;k--) d[k]=ar[0];
				return kei(d);
			}
			for(k=0;k<i+ar.size()-b;k++) d[i-k-1]=0;
			for(k=i+ar.size()-b;k<i;k++) d[i-k-1]=na[k-(i+ar.size()-b)];
			return kei(d);
		 }
		}
		long long x=1;for(i=0;i<d.size();i++) x*=10;return find(x,b);
	}
};
