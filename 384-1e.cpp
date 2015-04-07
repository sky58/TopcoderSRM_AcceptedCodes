//SRM384DOV1-250 Library
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
class Library{
	public:
	int Library::documentAccess(vector <string> a,vector <string> b,vector <string> c){
		int i,j,out=1;vector <vector <string> > d;vector <string> ret;vector <int> x,y;
		for(i=0;i<a.size();i++){x.push_back(0);y.push_back(0);}
//		if(b.size()==0 || c.size()==0 || a.size()==0) return 0;
		
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);vector <string> aa;
			for(j=0;j<3;j++){string v;sin>>v;aa.push_back(v);}
			d.push_back(aa);
		}
//		if(d[2][2]=="author") return 1;return 0;
		for(i=0;i<b.size();i++) for(j=0;j<d.size();j++) if(b[i]==d[j][2]) x[j]=1;
		for(i=0;i<c.size();i++) for(j=0;j<d.size();j++) if(c[i]==d[j][1]) y[j]=1;
		for(j=0;j<d.size();j++) if(x[j]==1 && y[j]==1) ret.push_back(d[j][0]);
		if(ret.size()==0) return 0;
		sort(ret.begin(),ret.end());
		for(i=1;i<ret.size();i++) if(ret[i]!=ret[i-1]) out++;
		return out;
	}
};
