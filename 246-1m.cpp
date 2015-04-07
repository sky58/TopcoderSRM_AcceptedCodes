//SRM246DIV1-500 CalcButton
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
class CalcButton{
	public:
	string CalcButton::getDigits(vector <string> a){
		string b="";int i,j,ma=-1;string out;
		for(i=0;i<a.size();i++) b+=a[i];int n=b.size();
		for(j=0;j<1000;j++){
			string c=moji(j);while(c.size()<3) c='0'+c;int t=0;
			for(i=0;i<n-2;i++){
				if(b.substr(i,3)==c){i+=2;t++;}
			}
			if(t>ma){ma=t;out=c;}
		}
		return out;
	}
};
