//SRM229DIV1-250
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
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string zikan(int a){
	if(a>=780) a-=720;
	string ret;
	int b=a/60;if(b<10) ret+='0';ret+=moji(b);ret+=':';
	int c=a%60;if(c<10) ret+='0';ret+=moji(c);
	return ret;
}
class Cafeteria{
	public:
	string Cafeteria::latestTime(vector <int> a,vector <int> b,vector <int> c){
		int mi=1000000;int i;
		stringstream out;
		for(i=0;i<a.size();i++){
			int s=c[i];while((s+a[i])%10!=0) s++;s+=b[i];mi=min(mi,s);
		}
		return zikan(870-mi);
	}
};
