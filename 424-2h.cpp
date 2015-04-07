//SRM424DIV2-900 BestRoads

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
class BestRoads{
	public:
	vector <int> BestRoads::numberOfRoads(std::vector <string> x, int m){
		vector <int> out,zyo,cl;int n=x.size(),i,j,k,t;
		
		for(i=0;i<n;i++){zyo.push_back(i);out.push_back(0);}
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) if(x[i][j]=='Y'){
			if(zyo[i]==zyo[j]) continue;
			t=zyo[j];for(k=0;k<n;k++) if(zyo[k]==t) zyo[k]=zyo[i];
			out[i]++;out[j]++;m--;x[i][j]='N';x[j][i]='N';
		}
//		return out;
		for(i=0;i<n-1;i++) if(zyo[i]!=zyo[i+1]) return cl;if(m==0) return out;
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) if(x[i][j]=='Y'){
			out[i]++;out[j]++;m--;if(m==0) return out;
		}
		return cl;
	}
};
