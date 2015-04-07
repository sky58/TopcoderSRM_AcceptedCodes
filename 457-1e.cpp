//SRM457DIV1-500 TheTriangleBothDIvs
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
string mojia(int a){
	if(a<0) return "-"+moji(-a);return "+"+moji(a);
}
bool comp(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i] && a[i]!='?') return true;
	}
	return false;
}
string mojib(int a){
	string out;out+=((a/10)+'0');out+=((a%10)+'0');
	return out;
}
class TheTriangleBothDivs{
	public:
	string TheTriangleBothDivs::fix(string a){
	int i,j,k,out=1440;
		for(i=0;i<24;i++) for(j=0;j<60;j++) for(k=-9;k<10;k++){
			string b=mojib(i)+":"+mojib(j)+" GMT"+mojia(k);
			if(comp(a,b)) continue;
			out=min(out,((i+24-k)%24)*60+j);
		}
		return mojib(out/60)+":"+mojib(out%60);
	}
};
