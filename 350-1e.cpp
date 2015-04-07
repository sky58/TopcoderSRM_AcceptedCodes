//SRM350DIV1-250 SumOfPerfectPowers
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
typedef long long lint;
int z[5000010];
lint po(int a,int b){
	lint ret=1;
	for(int i=0;i<b;i++) ret*=a;return ret;
}
class SumsOfPerfectPowers{
	public:
	int SumsOfPerfectPowers::howMany(int a,int b){
		vector <int> x,y;int i,j,out=0;
//		cout<<"a\n";
		for(i=2;i<23;i++){
			for(j=0;po(j,i)<5000000;j++) x.push_back((int)po(j,i));
		}
		memset(z,0,sizeof(z));sort(x.begin(),x.end());
//		cout<<"b\n";
		for(i=0;i<x.size();i++) for(j=0;j<=i && x[i]+x[j]<=5000000;j++) z[x[i]+x[j]]=1;
		for(i=a;i<=b;i++) out+=z[i];
		return out;
	}
};
