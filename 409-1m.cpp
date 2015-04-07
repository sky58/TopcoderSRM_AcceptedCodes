//SRM409DIV1-600 MagicalSpheres

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
vector <int> sosuu;
vector <int> soinsu;
int kei(int a, int b){
	int ret=0;
	while(b>0){
		ret+=b/a;b/=a;
	}
	return ret;
}

class MagicalSpheres{
	public:
	int MagicalSpheres::divideWork(int a, int b, int c){
		int i, j, t, f, s;
		sosuu.push_back(2);
		for(i=3;i<=110000;i++){
			f=0;
			for(j=0;sosuu[j]*sosuu[j]<=i;j++) if(i%sosuu[j]==0) f=1;
			if(f==0) sosuu.push_back(i);
		}
		for(i=0;i<sosuu.size();i++) soinsu.push_back(kei(sosuu[i],a+b)-kei(sosuu[i],a)-kei(sosuu[i],b));
		for(i=c;i>=1;i--){
			f=0;s=i;
			for(j=0;sosuu[j]<=s;j++){
				t=0;
				while(s%sosuu[j]==0){
					s/=sosuu[j];t++;
				}
				if(t>soinsu[j]) f=1;
			}
			if(f==0) return i;
		}
	}
};
