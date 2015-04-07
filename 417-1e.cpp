//SRM417DIV1-250(DIV2-500) TemplateMatching
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

int ten(string s1, string s2){
	int len=min(s1.size(),s2.size());
	int i, j, f, out=0;
	for(i=0;i<len;i++){
		f=0;
		for(j=0;j<=i;j++){
			if(s1[s1.size()-i-1+j]!=s2[j]){
				f=1;break;
			}
		}
		if(f==0) out=i+1;
	}
	return out;	
}

class TemplateMatching{
	public:
	string TemplateMatching::bestMatch(std::string in, std::string prefix, std::string suffix){
		string out="", ex;
		int i, j, t1, t2, b1=0, b2=0;
		out+=in[0];
		for(i=0;i<in.size();i++){
			for(j=i;j<in.size();j++){
				ex=in.substr(i,j-i+1);
				t1=ten(prefix,ex);t2=ten(ex,suffix);
				if(t1+t2>b1+b2 || (t1+t2==b1+b2 && t1>b1) || (t1==b1 && t2==b2 && ex<out)){
					out=ex;b1=t1;b2=t2;
				}
			}
		}
		return out;
	}
};
