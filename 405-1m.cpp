//SRM405DIV1-500 AllCycleLengths

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
class AllCycleLengths{
	public:
	string AllCycleLengths::findAll(vector <string> a){
		int now[40],next[40];vector <int> ret;string out;
		int i,j,k,n=a.size(),nowi=10000,nowj=10000,f;
		
		for(i=0;i<n;i++) now[i]=(1<<i);
		for(i=0;i<6000;i++){
			for(j=0;j<n;j++) next[j]=0;
			for(j=0;j<n;j++) for(k=0;k<n;k++) if(a[j][k]=='Y') next[k]=now[j]|next[k];
			f=0;for(j=0;j<n;j++) if(next[j]&(1<<j)){f=1;break;}ret.push_back(f);
			for(j=0;j<n;j++) now[j]=next[j];
		}
		
		for(i=1;i<2000;i++){
			for(j=6000-i-1;j>=0;j--) if(ret[j]!=ret[i+j]) break;
			if(i+j<nowi+nowj) {nowi=i;nowj=j;}
		}
		for(i=0;i<=nowj;i++) out+=(ret[i]+'0');out+='(';
		for(i=0;i<nowi;i++) out+=(ret[i+nowj+1]+'0');out+=')';
		return out;
	}
};
