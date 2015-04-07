//SRM317DIV1-250 PalindromicNumbers
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
class PalindromicNumbers{
	public:
	int PalindromicNumbers::countPalNums(int n,int m){
		int i,out=0;
		for(i=1;i<100000;i++){
			string a=moji(i),b=a.substr(0,a.size()-1);reverse(b.begin(),b.end());a+=b;
			istringstream sin(a);int s;sin>>s;
			if(s>=n && s<=m) out++;
			if(i<10000){
				a=moji(i);b=a;reverse(b.begin(),b.end());a+=b;
				istringstream sin(a);int s;sin>>s;
				if(s>=n && s<=m) out++;
			}
		}
		return out;
	}
};
