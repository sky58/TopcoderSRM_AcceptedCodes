//SRM303DIV1-250 SpiralNumbers
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
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string rec(int a,int b){
	return "("+moji(a)+","+moji(b)+")";
}
class SpiralNumbers{
	public:
	string SpiralNumbers::getPosition(int a){
		lint b=a,c;int i;if(a<2) return "(0,0)";
		for(i=1;i<50000;i+=2){
			c=i;if((c+2)*(c+2)>=a) break;
		}
		b-=c*c+1;
		if(b<c+1) return rec(-c/2+b,c/2+1);b-=c+1;
		if(b<c+1) return rec(c/2+1,c/2-b);b-=c+1;
		if(b<c+1) return rec(c/2-b,-c/2-1);b-=c+1;
		return rec(-c/2-1,-c/2+b);
	}
};
