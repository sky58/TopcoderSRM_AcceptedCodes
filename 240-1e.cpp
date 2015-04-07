//SRM240DIV1-250 TravellingByTrain
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
vector <pint> tr[55];
int de(string a){
	return (a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');
}
string en(int a){
	string ret="";
	ret+=(a/600+'0');a%=600;ret+=(a/60+'0');a%=60;ret+=':';ret+=(a/10+'0');a%=10;ret+=(a+'0');return ret;
}
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class TravellingByTrain{
	public:
	string TravellingByTrain::earliestArrival(vector <string> a){
		int i,j,now=540,n=a.size();string s;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			while(sin>>s){
				int x=de(s.substr(0,5)),y=de(s.substr(6,5));
				if(x>=y) tr[i].pb(mp(x,1440+y-x));else tr[i].pb(mp(x,y-x));
			}
		}
		for(i=0;i<n;i++){
			int next=100000000;
			for(j=0;j<tr[i].size();j++){
				next<?=now+(1440+tr[i][j].fi-now%1440)%1440+tr[i][j].se;
			}
			now=next;
		}
//		cout<<now<<endl;
		string out=en(now%1440);out+=", day ";out+=moji(now/1440+1);return out;
	}
};
