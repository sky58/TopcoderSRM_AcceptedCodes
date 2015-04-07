//SRM215DIV1-250 Diving
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
class Diving{
	public:
	string Diving::needed(string a,string b,string c){
		double bai,bor,p;string s;b="0"+b;int i;vector <double> po;
		istringstream sin(a);sin>>bai;
		istringstream sin1(b);sin1>>bor;
		istringstream sin3(c);
		rep(i,5){
			sin3>>s;if(s[0]=='?') continue;
			istringstream sin2(s);sin2>>p;po.pb(p);
		}
		rep(i,21){
			double t=0.5*i;vector <double> po2=po;po2.pb(t);sort(All(po2));
			if(bai*(po2[1]+po2[2]+po2[3])+1e-8>bor){
				return moji(i*5/10)+'.'+moji(i*5%10);
			}
		}
		return "-1.0";
	}
};
