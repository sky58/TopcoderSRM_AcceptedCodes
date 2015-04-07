//SRM335DIV1-250 Multifactorial
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
string moji(long long a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class Multifactorial{
	public:
	string Multifactorial::calcMultiFact(int n,int k){
		double inf=1.0e18;
		long long out=1;
		while(1){
			if((double)out>inf/n) return "overflow";
			out*=n;n-=k;if(n<=0) break;
		}
		return moji(out);
	}
};
