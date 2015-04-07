//SRM393DIV1-500 NSegmentDisplay

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
class NSegmentDisplay{
	public:
	string NSegmentDisplay::brokenSegments(vector <string> a,vector <string> b){
		string out="",ret;int i,j,k,m=a.size(),n=b.size(),s=a[0].size(),f,ff;
		
		for(i=0;i<s;i++) out+='?';
		for(i=0;i<n;i++) for(j=0;j<s;j++) if(b[i][j]=='1') out[j]='Y';
		for(i=0;i<n;i++){
			f=0;ret="";
			for(j=0;j<s;j++){
				if(out[j]=='Y') ret+='Y';else ret+='N';}
			for(j=0;j<m;j++){
				ff=0;
				for(k=0;k<s;k++) if(out[k]=='Y' && b[i][k]!=a[j][k]) ff=1;
				if(ff==0){
					f=1;
					for(k=0;k<s;k++) if(ret[k]=='N' && a[j][k]=='0') ret[k]='?';
				}
			}
			if(f==0) return "INCONSISTENT";
			for(k=0;k<s;k++) if(ret[k]=='N') out[k]='N';
		}
		return out;
	}
};
