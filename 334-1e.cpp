//SRM334DIV1-250 EncodedSum
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
typedef pair<long long,int> pint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
class EncodedSum{
	public:
	long long EncodedSum::maximumSum(vector <string> a){
		vector <long long> c;c.push_back(1);vector <int> d;
		int i,j,k;long long out=0;
		vector <pint> b;for(i=0;i<10;i++) b.pb(mp(0,0));
		
		for(i=0;i<12;i++) c.push_back(c[i]*10);
		for(i=0;i<a.size();i++){
			long long t=0;reverse(a[i].begin(),a[i].end());
			for(j=0;j<a[i].size();j++){
				b[(a[i][j]-'A')].fi+=c[j];
				if(j==a[i].size()-1) b[(a[i][j]-'A')].se=1;
			}
		}
		sort(b.begin(),b.end());reverse(b.begin(),b.end());
		for(i=0;i<b.size();i++) d.pb(9-i);
		if(b[b.size()-1].se==1 && d[d.size()-1]==0){
			for(j=b.size()-2;j>=0;j--){
				if(b[j].se!=1){
					for(k=b.size()-1;k>j;k--){
						d[k]=d[k-1];
					}
					d[j]=0;break;
				}
			}
		}
//		for(i=0;i<d.size();i++) cout<<d[i]<<'\n';
		for(i=0;i<b.size();i++) out+=b[i].fi*d[i];
		return out;
	}
};
