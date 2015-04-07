//SRM404DIV1-500 KSubstring
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
typedef vector<int> vint;
typedef pair<long long,long long> plong;
#define mp make_pair 
class KSubstring{
	public:
	vector <int> KSubstring::maxSubstring(int a0, int x, int y, int m, int n){
		vector <long long> a;int i,j,mi=2000000000,mik=0,k;vector <int> out;
		a.push_back(a0);for(i=1;i<n;i++) a.push_back(((long long)a[i-1]*x+y)%m);
		
		for(i=1;i<=n/2;i++){
			vector <plong> b;long long t=0,mini=2000000000,minik=0,mm,nn;
			for(j=0;j<i;j++) t+=a[j];b.push_back(mp(t,0));
			for(j=i;j<n;j++){
				t+=a[j];t-=a[j-i];b.push_back(mp(t,j-i+1));
			}
			sort(b.begin(),b.end());j=0;
			while(j<b.size()-1){
				k=j+1;while(1){if(b[j].first!=b[k+1].first) break;if(k==b.size()-1) break;k++;}
				mm=abs(b[j].first-b[k].first);nn=min(i,(int)abs(b[j].second-b[k].second));
				if(mini>mm || (mini==mm && minik<nn)){mini=mm;minik=nn;}j=k;
			}
			if(mi>mini || (mi==mini && mik<minik)){mi=mini;mik=minik;}
		}
		out.push_back((int)mik);out.push_back((int)mi);
		return out;
	}
};
