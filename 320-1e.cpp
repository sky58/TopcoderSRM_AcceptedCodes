//SRM320DIV1-250 ExtraordinarilyLarge
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
lint rui(lint a){
	lint ret=1;if(a==0) return 1;
	for(lint i=a;i>=1;i--){
		ret*=i;if(ret>2000000000) return 2000000000;
	}
	return ret;
}
class ExtraordinarilyLarge{
	public:
	string ExtraordinarilyLarge::compare(string a,string b){
		lint c=0,d=0;int x=0,y=0,i;
		for(i=0;i<a.size();i++){
			if(a[i]=='!') x++;
			else{c*=10;c+=(a[i]-'0');}
		}
		for(i=0;i<b.size();i++){
			if(b[i]=='!') y++;
			else{d*=10;d+=(b[i]-'0');}
		}
		if(c==0 && x>0){c=1;x=0;}
		if(d==0 && y>0){d=1;y=0;}
		if(c==d && x==y) return "x=y";
		if(c<d && x<=y) return "x<y";
		if(c>d && x>=y) return "x>y";
		if(x>y){
			for(i=0;i<x-y;i++){
				c=rui(c);if(c>d) return "x>y";
			}
			if(c==d) return "x=y";return "x<y";
		}
		if(x<y){
			for(i=0;i<y-x;i++){
				d=rui(d);if(c<d) return "x<y";
			}
			if(c==d) return "x=y";return "x>y";
		}
	}
};
