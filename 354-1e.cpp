//SRM354DIV1-300 DateFormat
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
int mo[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string de(int x,int y){
	string a=moji(x),b=moji(y);
	if(a.size()<2) a="0"+a;if(b.size()<2) b="0"+b;
	return a+"/"+b;
}
class DateFormat{
	public:
	string DateFormat::fromEuropeanToUs(vector <string> a){
		int i,x,y;char z;vector <int> d1,d2;string out="",b="",s="";pint now=mp(0,0);
		for(i=0;i<a.size();i++) b+=a[i];istringstream sin(b);
		while(sin>>s){
			istringstream sin2(s);sin2>>x>>z>>y;
			d1.pb(min(x,y));d2.pb(max(x,y));
		}
		for(i=0;i<d1.size();i++){
			if(d1[i]<1 || d1[i]>12) return "";
			if(mo[d1[i]]<d2[i]) return "";
			if(mp(d1[i],d2[i])>now){now=mp(d1[i],d2[i]);out+=de(d1[i],d2[i]);}
			else if(mp(d2[i],d1[i])>now){now=mp(d2[i],d1[i]);out+=de(d2[i],d1[i]);}
			else return "";
			if(i<d1.size()-1) out+=" ";
			if(now.fi>12) return "";
		}
		return out;
	}
};
