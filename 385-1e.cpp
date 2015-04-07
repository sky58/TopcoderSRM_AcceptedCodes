//SRM385DIV1-250(DIV2-500) UnderscoreJusitification
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
class UnderscoreJustification{
	public:
	string UnderscoreJustification::justifyLine(vector <string> a,int k){
		int n=a.size(),i,j,z,m;string out=a[0];
		
		for(i=0;i<n;i++) k-=a[i].size();m=k/(n-1);z=k%(n-1);
		for(i=1;i<n;i++){
			if(z==0) for(j=0;j<m;j++) out+='_';
			else if(z==n-i){for(j=0;j<=m;j++) out+='_';z--;}
			else if(a[i][0]<'a') for(j=0;j<m;j++) out+='_';
			else{for(j=0;j<=m;j++) out+='_';z--;}
			out+=a[i];
		}
		return out;
	}
};
