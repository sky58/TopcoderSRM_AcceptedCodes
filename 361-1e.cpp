//SRM361DIV1-250 WhiteHats
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
class WhiteHats{
	public:
	int WhiteHats::whiteNumber(vector <int> a){
		sort(a.begin(),a.end());int i,f=0;
		if(a[a.size()-1]>=a.size()) return -1;
		for(i=0;i<a.size()-1;i++){
			if(a[i]!=a[i+1]) f++;
		}
		if(f==0){
			if(a.size()-1==a[0]) return a.size();
			if(a[0]==0) return 0;
			return -1;
		}
		if(f==2) return -1;int sf=a[0];
		for(i=0;i<=sf;i++) a[i]++;
		for(i=0;i<a.size()-1;i++) if(a[i]!=a[i+1]) return -1;return a[0];
	}
};
