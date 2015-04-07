//SRM382DIV1-500 PointsOnACircle

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
vector <int> a;int b[370];

int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}

int ke(vector <int> t){
	vector <int> iro,len;
	int i,ret=0,na=1,now=t[0];
	
	for(i=1;i<t.size();i++){
		if(now!=t[i]){
			iro.push_back(now);
			len.push_back(na);
			na=1;now=t[i];
		}
		else na++;
	}
	iro.push_back(now);len.push_back(na);
	int n=iro.size();
	if(n==1) return iro[0]*len[0]/2;
	if(iro[0]==1 && iro[n-1]==1){
		len[0]+=len[n-1];n--;
	}
	for(i=0;i<n;i++) ret+=iro[i]*len[i]/2;
	return ret;
}

int kei(int n){
	int g=gcd(360,n),ret=0,i,j;
	
	for(i=0;i<g;i++){
		vector <int> c;
		for(j=0;j<360/g;j++) c.push_back(b[(i+j*n)%360]);
		ret+=ke(c);
	}
	return ret;
}

class PointsOnACircle{
	public:
	int PointsOnACircle::color(vector <string> aa){
		string aaa;int i,out=0;
		
		for(i=0;i<aa.size();i++) aaa+=aa[i];
		istringstream sin(aaa);
		for(int v;sin>>v;a.push_back(v));
		for(i=0;i<a.size();i++) b[a[i]]=1;
		for(i=1;i<360;i++) out=max(out,kei(i));
		return out*2;
	}
};
