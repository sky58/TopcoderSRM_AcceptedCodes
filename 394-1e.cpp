//SRM294DIV1-250 RoughStrings
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
class RoughStrings{
	public:
	int RoughStrings::minRoughness(string a,int n){
		 vector <int> t;int i,j,k,f;
		 
		 for(i=0;i<26;i++) t.push_back(0);
		 for(i=0;i<a.size();i++) t[(a[i]-'a')]++;
//		 return t[0];
//		 sort(t.begin(),t.end(),greater<int>());
		 for(i=0;i<60;i++) for(j=1;j<60;j++){
		 	f=0;
		 	for(k=0;k<26;k++){
		 		if(t[k]<j) f+=t[k];
		 		if(t[k]>j+i) f+=(t[k]-j-i);
		 	}
		 	if(f<=n) return i;
		 }
		 return 100;
	}
};
