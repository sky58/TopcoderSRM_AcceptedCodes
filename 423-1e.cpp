//SRM423DIV1-300(DIV2-600) TheTower
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
class TheTower{
	public:
	vector <int> TheTower::count(std::vector <int> x, std::vector <int> y){
		vector <int> out, t, tt;int i, j, k, o, min, a, n;
		n=x.size();
		for(i=0;i<n;i++) out.push_back(1000000000);
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			t=tt;for(k=0;k<n;k++) t.push_back(abs(x[i]-x[k])+abs(y[j]-y[k]));
			sort(t.begin(),t.end());a=0;
			for(k=0;k<n;k++){
				a+=t[k];if(out[k]>a) out[k]=a;
			}
		}
		return out;
	}
};
