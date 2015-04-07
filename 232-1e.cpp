//SRM232DIV1-250 WordFind
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
bool ma(string a,string b){
	if(a.size()<b.size()) return false;
	if(a.substr(0,b.size())==b) return true;return false;
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class WordFind{
	public:
	vector <string> WordFind::findWords(vector <string> a,vector <string> b){
		vector <string> out;int i,j,k,l,x=a.size(),y=a[0].size(),f;
		for(i=0;i<b.size();i++){
			f=0;
			for(j=0;j<x;j++) for(k=0;k<y;k++){
				if(f==1) continue;string c,d,e;
				for(l=j;l<x;l++) c+=a[l][k];
				for(l=k;l<y;l++) d+=a[j][l];
				for(l=0;j+l<x && k+l<y;l++) e+=a[j+l][k+l];
				if(ma(c,b[i]) || ma(d,b[i]) || ma(e,b[i])){
					out.push_back(moji(j)+' '+moji(k));f=1;
				}
			}
			if(f==0) out.push_back("");
		}
		return out;
	}
};
