//SRM396DIV1-250 DNAString
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
class DNAString{
	public:
	int DNAString::minChanges(int n,vector <string> a){
		string b="";int i,j,k,out=2000000000,t;
		
		for(i=0;i<a.size();i++) b+=a[i];
		for(i=1;i<=n;i++){
			t=0;
			for(j=0;j<i;j++){
				vector <int> c;for(k=0;k<4;k++) c.push_back(0);
				for(k=j;k<b.size();k+=i){
					if(b[k]=='A') c[0]++;
					if(b[k]=='C') c[1]++;
					if(b[k]=='G') c[2]++;
					if(b[k]=='T') c[3]++;
				}
//				sort(c.begin(),c.end());t+=(c[0]+c[1]+c[2]);
				t+=(c[0]+c[1]+c[2]+c[3]-max(max(c[0],c[1]),max(c[2],c[3])));
			}
			out=min(t,out);
		}
		return out;
	}
};
