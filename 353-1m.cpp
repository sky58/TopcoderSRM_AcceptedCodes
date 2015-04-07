//SRM353DIV1-500 FlatformJumper

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
typedef pair<int,int> pint;
#define mp make_pair
class PlatformJumper{
	public:
	int PlatformJumper::maxCoins(vector <string> a,int b,int c){
		vector <pint> ba;vector <int> px,py,co,po;
		int out=0,n=a.size(),i,j;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			int x,y,z;sin>>x>>y>>z;
			ba.push_back(mp(x+y*10000,z));
		}
		sort(ba.begin(),ba.end());reverse(ba.begin(),ba.end());
		for(i=0;i<n;i++){
			px.push_back(ba[i].first%10000);
			py.push_back(ba[i].first/10000);
			co.push_back(ba[i].second);
			po.push_back(0);
		}
		po[0]=co[0];
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				int sx=abs(px[i]-px[j]),sy=py[j]-py[i];
				if((long long)sx*sx*c<=(long long)2*sy*b*b) po[i]=max(po[i],po[j]);
			}
			po[i]+=co[i];
		}
		for(i=0;i<n;i++) out=max(out,po[i]);
		return out;
	}
};
