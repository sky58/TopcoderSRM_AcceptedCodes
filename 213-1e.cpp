//SRM213DIV1-250 Taxicab
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class Taxicab{
	public:
	string Taxicab::calculateFare(vector <int> a){
		int i,n=a.size(),t=0,out=250;
		rep(i,n){
			if(a[i]<2) t+=4;else t+=a[i];
		}
		if(t>4) out+=10*(t-4);
		string ret=moji(out);//(out/100)+"."+(out/10%10+'0')+(out%10+'0');
		return ret.substr(0,ret.size()-2)+"."+ret.substr(ret.size()-2);
	}
};
