//SRM415DIV1-250 ShipLoading
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
#define All(s) s.begin(),s.end()
class ShipLoading{
	public:
	int ShipLoading::minimumTime(std::vector <int> c, std::vector <string> b){
		vector <int> a;int i, j, out=0;string str;
		
		for(i=0;i<b.size();i++) str+=b[i];
		istringstream sin(str);
		for(int v;sin>>v;a.push_back(v));
		sort(All(c),greater<int>());sort(All(a),greater<int>());
		if(c[0]<a[0]) return -1;
		while(1){
			if(a[0]==0) return out;
			for(i=0;i<c.size();i++){
				for(j=0;j<a.size();j++){
					if(c[i]>=a[j] && a[j]>0){
						a[j]=0;break;
					}
				}
			}
			sort(All(a),greater<int>());out++;
		}
	}
};
