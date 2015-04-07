//SRM257DIV1-450 StockQuotes
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
int ke[15],ka[15],bi[15],as[15];
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
string cal(int a,int b){
	string c="";int t=a*200/b+1;t/=2;c=moji(t%100);while(c.size()<2) c='0'+c;
	return moji(t/100)+'.'+c;
}
class StockQuotes{
	public:
	vector <string> StockQuotes::report(vector <string> a){
		int kei=0,kaz=0,i,j,nbi=0,nas=10000,x,y,z;vector <string> out;
		memset(ka,0,sizeof(ka));memset(ke,0,sizeof(ke));memset(bi,0,sizeof(bi));memset(as,10000,sizeof(as));
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);sin>>x>>y>>z;bi[x]=y;as[x]=z;ka[x]++;ke[x]+=(z-y);
			int bi2=0,as2=10000;
			for(j=0;j<10;j++){bi2>?=bi[j];as2<?=as[j];}
			if(bi2!=nbi || as2!=nas){
				nbi=bi2;nas=as2;ka[10]++;ke[10]+=(nas-nbi);
			}
		}
		for(i=0;i<=10;i++){
			if(ka[i]>0){
				out.pb(moji(i)+' '+moji(ka[i])+' '+cal(ke[i],ka[i]));
			}
		}
//		cout<<ke[10]<<' '<<ka[10]<<endl;
		return out;
	}
};
