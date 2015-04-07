//SRM402DIV1-450 LargestGap

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
class LargestGap{
	public:
	int LargestGap::getLargest(vector <string> bo){
		string bor="",iro="";vector <int> len,ind;
		int i,j,n,na=1,ma=0,mi=0,out,fo,ba;char now=bo[0][0];
		
		for(i=0;i<bo.size();i++) bor+=bo[i];
		for(i=1;i<bor.size();i++){
			if(now!=bor[i]){
				iro+=now;len.push_back(na);ind.push_back(i-na);
				na=1;now=bor[i];
			}
			else na++;
		}
		iro+=now;len.push_back(na);ind.push_back(bor.size()-na);
		n=iro.size();
		if(iro[0]==iro[iro.size()-1]){
			len[0]+=len[iro.size()-1];n--;
		}
		for(i=0;i<n;i++) if(iro[i]=='X'){
			fo=len[(i+1)%n];ba=len[(i+n-1)%n];
			if(fo+ba>ma || (fo+ba==ma && min(fo,ba)>mi)){out=ind[i];ma=fo+ba;mi=min(fo,ba);}
		}
		return out;
	}
};
