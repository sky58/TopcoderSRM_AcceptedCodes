//SRM363DIV1-500 MirrorNumber

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
long long x,y;int out=0;
int ue[5]={0,1,2,5,8},si[5]={0,1,5,2,8};
int ma[3]={0,1,8};
long long esa[7]={0,1,8,11,25,52,88};
vector <long long> zyo;
void kei(int b,int c,long long d){
	int i;
	if(c==0){
		for(i=1;i<5;i++) kei(b,c+1,d+zyo[b-c]*ue[i]+zyo[c]*si[i]);
	}
	else if(c==b/2){
		if(b%2==0){
			for(i=0;i<3;i++){
				long long a=d+zyo[c]*ma[i];if(a>=x && a<=y) out++;
			}
		}
		else{
			for(i=0;i<5;i++){
				long long a=d+zyo[b-c]*ue[i]+zyo[c]*si[i];if(a>=x && a<=y) out++;
			}
		}
	}
	else{
		for(i=0;i<5;i++) kei(b,c+1,d+zyo[b-c]*ue[i]+zyo[c]*si[i]);
	}
	return;
}
class MirrorNumber{
	public:
	int MirrorNumber::count(string a,string b){
		int i;
		x=0;y=0;
		for(i=0;i<a.size();i++){x*=10;x+=(a[i]-'0');}
		for(i=0;i<b.size();i++){y*=10;y+=(b[i]-'0');}
		zyo.push_back(1);for(i=0;i<17;i++) zyo.push_back(zyo[i]*10);
		for(i=2;i<18;i++) kei(i,0,0);
		for(i=0;i<7;i++) if(esa[i]<=y && esa[i]>=x) out++;
		return out;
	}
};
