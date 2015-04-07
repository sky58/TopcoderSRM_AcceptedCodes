//SRM373DIV1-250 StringFragmantation
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
#include<queue>
#include<deque>
using namespace std;
class StringFragmentation{
	public:
	int StringFragmentation::largestFontSize(string str,int b,int c){
		int i,x=11000,y=0,max=0;vector <string> a;
		istringstream sin(str);
		for(string v;sin>>v;a.push_back(v));
		for(i=0;i<a.size();i++) max>?=a[i].size();
		while(x>y){
			int z=(x+y+1)/2,h=0,w=11000;
			if(max*(z+2)>b){x=z-1;continue;}
			for(i=0;i<a.size();i++){
				if((w+a[i].size()+1)*(z+2)<=b) w+=(a[i].size()+1);else{h++;w=a[i].size();}
			}
			if(h*z*2<=c) y=z;else x=z-1;
		}
		if(x<8) return -1;return x;
	}
};
