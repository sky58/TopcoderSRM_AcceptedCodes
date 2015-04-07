//SRM301DIV1-250 IndicatorMotionReverse
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
string ka(int a){
	string ret="";
	ret+=((a/10)+'0');ret+=((a%10)+'0');
	return ret;
}
string de(char a,int b){
	string ret="";
	ret+=a;ret+=ka((b-1)%99+1);
	for(int i=0;i<(b-1)/99;i++){ret+=a;ret+="99";}
	return ret;
}
class IndicatorMotionReverse{
	public:
	string IndicatorMotionReverse::getMinProgram(vector <string> a){
		int i,j;string c="",d="";vector <int> b;
		for(i=0;i<a.size();i++) for(j=0;j<a[i].size();j++){
			if(a[i][j]=='|') b.pb(0);
			if(a[i][j]=='N') b.pb(1);
			if(a[i][j]=='-') b.pb(2);
			if(a[i][j]=='/') b.pb(3);
		}
		for(i=1;i<b.size();i++){
			if((b[i]+4-b[i-1])%4==0) c+='S';
			if((b[i]+4-b[i-1])%4==1) c+='L';
			if((b[i]+4-b[i-1])%4==2) c+='F';
			if((b[i]+4-b[i-1])%4==3) c+='R';
		}
		if(c.size()<1) return "";
		char now=c[0];int t=1;
		for(i=1;i<c.size();i++){
			if(c[i]!=now){d+=de(now,t);t=1;now=c[i];}
			else t++;
		}
		d+=de(now,t);
		if(d.size()>100) return d.substr(0,97)+"...";return d;
	}
};
