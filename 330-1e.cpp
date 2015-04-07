//SRM330DIV1-250 Arrows
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
#define pb push_back
class Arrows{
	public:
	int Arrows::longestArrow(string a){
		int n=a.size(),i,j,out=-1;
		for(i=0;i<n;i++){
			if(a[i]=='-' || a[i]=='=') continue;
			if(a[i]=='<'){
				for(j=1;j+i<n;j++){
					if(a[i+j]=='<' || a[i+j]=='>') break;
					if(j!=1 && a[i+j]!=a[i+j-1]) break;
				}
				out>?=j;
			}
			if(a[i]=='>'){
				for(j=1;i-j>=0;j++){
					if(a[i-j]=='<' || a[i-j]=='>') break;
					if(j!=1 && a[i-j]!=a[i-j+1]) break;
				}
				out>?=j;
			}
		}
		return out;
	}
};
