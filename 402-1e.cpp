//SRM402DIV1-250(DIV2-1000) RandomSort
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
map<int,double> memo;
double kei(vector <int> a, int goal){
	int i, j, t=0, kazu=0, d;double ret=0.0;
	vector <int> aa;
	for(i=0;i<a.size();i++){
		t*=10;t+=a[i];
	}
	if(t==goal) return 0.0;
	if(memo[t]) return memo[t];
	for(i=0;i<a.size()-1;i++) for(j=i+1;j<a.size();j++){
		if(a[i]>a[j]){
			kazu++;
			aa=a;d=aa[i];aa[i]=aa[j];aa[j]=d;
			ret+=kei(aa, goal);
		}
	}
	ret/=kazu;ret+=1.0;return memo[t]=ret;
}

class RandomSort{
	public:
	double RandomSort::getExpected(std::vector <int> a){
		int i,goal=0;
		for(i=0;i<a.size();i++){
			goal*=10;goal+=(i+1);
		}
		return kei(a,goal);
	}
};
