//SRM414DIV1-500 StringInterspersal

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
bool check(string a,string b){
	int i;
	for(i=0;i<a.size() && i<b.size();i++){
		if(a[i]>b[i])return true;
		if(a[i]<b[i])return false;
	}
	if(a.size()<b.size()){
		b=b.substr(a.size(),b.size()-a.size());
		return check(a,b);
	}
	if(a.size()>b.size()){
		a=a.substr(b.size(),a.size()-b.size());
		return check(a,b);
	}
	return true;
}
class StringInterspersal{
	public:
	string StringInterspersal::minimum(vector <string> a){
		string out="",d,f;char maxc;int i,j,maxi,n=0;vector <int> b;
		for(i=0;i<a.size();i++){
			n+=a[i].size();b.push_back(0);
		}
		for(i=0;i<n;i++){
			maxc='z';d="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
			for(j=0;j<a.size();j++){
				if(b[j]>=a[j].size()) continue;
				if(a[j][b[j]]>maxc) continue;
				f=a[j].substr(b[j],a[j].size()-b[j]);
				if(a[j][b[j]]==maxc && check(f,d)) continue;
				maxi=j;maxc=a[j][b[j]];d=f;
			}
			out+=maxc;b[maxi]++;
		}
		return out;
	}
};
