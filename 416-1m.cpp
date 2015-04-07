//SRM416DIV1-500 CustomDice

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
class CustomDice{
	public:
	int CustomDice::countDice(int a){
		int i, j, m=1000000007;long long out=0;
		vector <int> k;
		if(a<4) return 0;
		a*=6;a-=21;
		for(i=0;i<=a;i++) k.push_back(1);
		for(i=2;i<=6;i++) for(j=i;j<=a;j++){
			k[j]+=k[j-i];k[j]=k[j]%m;
		}
		for(i=0;i<=a;i++) out+=k[i];out*=30;out=out%m;
		return int(out);
	}
};
