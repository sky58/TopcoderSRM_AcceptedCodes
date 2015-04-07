//SRM433DIV1-250 MagicWords
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
vector <int> ya;int si;
int kei(string a){
	for(int i=0;i<ya.size();i++){
		int f=0,t=si/ya[i];
		for(int j=0;j<si;j++) if(a[j]!=a[(j+ya[i])%si]) f=1;
		if(f==0) return t;
	}
	return 1;
}
int kai(int a){
  if(a==1) return 1;return a*kai(a-1);
}

class MagicWords{
  public:
  int MagicWords::count(vector <string> a,int b){
    int i,out=0;
//    for(i=0;i<a.size();i++) sa+=a[i];
	si=0;
	for(i=0;i<a.size();i++) si+=a[i].size();
	for(i=1;i<si;i++){
		if(si%i==0) ya.push_back(i);
	}
    sort(a.begin(),a.end());
    do{
      string c;
      for(i=0;i<a.size();i++) c+=a[i];
      if(kei(c)==b) out++;
    }while(next_permutation(a.begin(),a.end()));
    vector <int> k,l;for(i=0;i<a.size();i++) k.push_back(0);
    for(i=0;i<a.size()-1;i++){
      if(k[i]==1) continue;
      int t=0;
      for(int j=i+1;j<a.size();j++){
        if(a[i]==a[j]){t++;k[j]=1;}
      }
      l.push_back(t);
    }
    for(i=0;i<l.size();i++) out*=kai(l[i]+1);
    return out;
  }
};
