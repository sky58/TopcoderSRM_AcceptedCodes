//SRM230DIV1-900 MultiReplacer

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
int m;vector <long long> base;
map<int ,vector <long long> > memo;
vector <long long> kei(int s){
	if(s==1) return base;
	if(memo[s].size()) return memo[s];
	vector <long long> ret,a,b;int i;
	a=kei(s/2);b=kei(s-s/2);
	for(i=0;i<9;i++) ret.push_back(0);
	ret[0]=(a[0]*b[0])%m+(a[3]*b[1])%m+(a[6]*b[2])%m;
	ret[1]=(a[1]*b[0])%m+(a[4]*b[1])%m+(a[7]*b[2])%m;
	ret[2]=(a[2]*b[0])%m+(a[5]*b[1])%m+(a[8]*b[2])%m;
	ret[3]=(a[0]*b[3])%m+(a[3]*b[4])%m+(a[6]*b[5])%m;
	ret[4]=(a[1]*b[3])%m+(a[4]*b[4])%m+(a[7]*b[5])%m;
	ret[5]=(a[2]*b[3])%m+(a[5]*b[4])%m+(a[8]*b[5])%m;
	ret[6]=(a[0]*b[6])%m+(a[3]*b[7])%m+(a[6]*b[8])%m;
	ret[7]=(a[1]*b[6])%m+(a[4]*b[7])%m+(a[7]*b[8])%m;
	ret[8]=(a[2]*b[6])%m+(a[5]*b[7])%m+(a[8]*b[8])%m;
	for(i=0;i<9;i++) ret[i]%=m;
	return memo[s]=ret;
}
class MultiReplacer{
	public:
	long long MultiReplacer::length(string a,string b,string c,int n,int M){
		long long out=0;int i;m=M;
		for(i=0;i<9;i++) base.push_back(0);
		for(i=0;i<a.size();i++){
			if(a[i]=='a') base[0]++;
			if(a[i]=='b') base[3]++;
			if(a[i]=='c') base[6]++;
		}
		for(i=0;i<b.size();i++){
			if(b[i]=='a') base[1]++;
			if(b[i]=='b') base[4]++;
			if(b[i]=='c') base[7]++;
		}
		for(i=0;i<c.size();i++){
			if(c[i]=='a') base[2]++;
			if(c[i]=='b') base[5]++;
			if(c[i]=='c') base[8]++;
		}
//		for(i=0;i<9;i++) printf("%d ",(int)base[i]);printf("\n");
		vector <long long> ret=kei(n);
//		for(i=0;i<9;i++) printf("%d ",(int)ret[i]);printf("\n");
		for(i=0;i<3;i++) out+=ret[i*3];out%=m;return out;
	}
};
