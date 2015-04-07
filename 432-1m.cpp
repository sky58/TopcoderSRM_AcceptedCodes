//SRM432DIV1-500 GroupedWord
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

bool bad(string a){
  vector <int> f;int i;
  for(i=0;i<26;i++) f.push_back(0);
  f[(a[0]-'a')]++;
  for(i=1;i<a.size();i++){
    if(a[i]!=a[i-1] && f[(a[i]-'a')]>0) return true;
    f[(a[i]-'a')]++;
  }
  return false;
}
class GroupedWord{
	public:
	string GroupedWord::restore(vector <string> a){
		string out;int i,j;
		vector <string> b,c;
		for(j=0;j<26;j++){
			string d;
			for(i=0;i<a.size();i++) if(a[i][0]==(j+'a') && a[i][a[i].size()-1]==(j+'a')){
				d+=a[i];a[i]="Z";
			}
			if(d.size()>0) b.push_back(d);
		}
		for(i=0;i<a.size();i++){
			if(a[i]!="Z") b.push_back(a[i]);
		}
		a=b;b=c;
		for(i=0;i<a.size();i++){
			if(a[i]=="Z" || a[i][0]!=a[i][a[i].size()-1]) continue;
			for(j=0;j<a.size();j++){
				if(i==j || a[i]=="Z") continue;
				if(a[j][0]==a[i][0]){a[i]+=a[j];a[j]="Z";break;}
				if(a[j][a[j].size()-1]==a[i][0]){a[i]=a[j]+a[i];a[j]="Z";break;}
			}
		}
		for(int l=0;l<10;l++){
		for(i=0;i<a.size();i++){
			if(a[i]!="Z") b.push_back(a[i]);
		}
		a=b;b=c;
		for(i=0;i<a.size();i++){
			if(a[i]=="Z") continue;
			for(j=0;j<a.size();j++){
				if(i==j || a[j]=="Z") continue;
				if(a[j][0]==a[i][a[i].size()-1]){a[i]=a[i]+a[j];a[j]="Z";}
				if(a[i][0]==a[j][a[j].size()-1]){a[i]=a[j]+a[i];a[j]="Z";}
			}
		}
		}
		for(i=0;i<a.size();i++){
			if(a[i]!="Z") b.push_back(a[i]);
		}
		for(i=0;i<b.size();i++) out+=b[i];
		if(bad(out)) return "IMPOSSIBLE";
		if(b.size()==1) return out;
		return "MANY";
	}
};
