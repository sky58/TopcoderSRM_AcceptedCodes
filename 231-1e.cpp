//SRM231DIV1-200 Stitch
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
class Stitch{
	public:
	vector <string> Stitch::stitch(vector <string> a,vector <string> b,int c){
		int i,j;vector <string> out;
		for(i=0;i<a.size();i++){
			string d;
			for(j=0;j<a[i].size()-c;j++) d+=a[i][j];
			for(j=0;j<c;j++){
				int x,y,z;
				x=a[i][a[i].size()-c+j]-0;y=b[i][j]-0;
				z=2*((c-j)*x+(j+1)*y)/(c+1);
				z=(z+1)/2;
				char w=z+0;d+=w;
			}
			for(j=c;j<b[i].size();j++) d+=b[i][j];
			out.push_back(d);
		}
		return out;
	}
};
