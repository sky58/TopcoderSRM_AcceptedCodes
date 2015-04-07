//SRM400DIV1-250 StrongPrimePower
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
long long n;

int kei(int a, int b, int p){
	int i,c=(a+b)/2;long long k=1;
	if(a>b) return -1;
	for(i=0;i<p;i++){
		if(k>n/c) return kei(a,c-1,p);k*=c;
	}
	if(k==n) return c;return kei(c+1,b,p);
}

class StrongPrimePower{
	public:
	vector <int> StrongPrimePower::baseAndExponent(string a){
		vector <int> sosuu,out;int i, j, f,t;
		for(i=0;i<a.size();i++){n*=10;n+=(a[i]-'0');}
		sosuu.push_back(2);sosuu.push_back(3);
		for(i=5;i<=110000;i+=2){
			f=0;
			for(j=1;sosuu[j]*sosuu[j]<=i;j++) if(i%sosuu[j]==0) f=1;
			if(f==0) sosuu.push_back(i);
		}
		for(i=59;i>1;i--){
			t=kei(2,1000000000,i);
			if(t!=-1){
				f=0;for(j=0;sosuu[j]*sosuu[j]<t;j++) if(t%sosuu[j]==0) f=1;
				if(f==1) return out;
				out.push_back(t);out.push_back(i);return out;
			}
		}
		return out;
	}
};
