//SRM262DIV1-500 BestYahtzeeScore
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
int cal(string a){
	vector <int> b;int i,ret=0,j;
	for(i=0;i<5;i++) b.pb(a[i]-'0');
	sort(b.begin(),b.end());
	if(b[0]==b[4]) return 50;
	if(b[0]==b[3] || b[1]==b[4]){
		for(i=0;i<5;i++) ret+=b[i];return ret;
	}
	if(b[0]==b[2] && b[3]==b[4]) return 25;
	if(b[0]==b[1] && b[2]==b[4]) return 25;
	if(b[1]-b[0]==1 && b[2]-b[1]==1 && b[3]-b[2]==1 && b[4]-b[3]==1) return 40;
//	if(b[1]-b[0]==1 && b[2]-b[1]==1 && b[3]-b[2]==1) return 30;
//	if(b[2]-b[1]==1 && b[3]-b[2]==1 && b[4]-b[3]==1) return 30;
	for(i=0;i<5;i++){
		vector <int> c;for(j=0;j<5;j++){if(i!=j) c.pb(b[j]);}
		if(c[1]-c[0]==1 && c[2]-c[1]==1 && c[3]-c[2]==1) return 30;
	}
	return 0;
}
	
class BestYahtzeeScore{
	public:
	int BestYahtzeeScore::bestScore(string a){
		int i,j,k,l,out=0;//cout<<cal("56443")<<endl;
		for(i=0;i<32;i++){
			string b="";for(j=0;j<5;j++){if(i&(1<<j)) b+=a[j];}int k1=__builtin_popcount(i);
			for(j=0;j<(1<<(5-k1));j++){
				string c=b;for(k=0;k<5-k1;k++){if(j&(1<<k)) c+=a[k+5];}int k2=__builtin_popcount(j);
				for(k=0;k<(1<<(5-k1-k2));k++){
					string d=c;for(l=0;l<5-k1-k2;l++){if(k&(1<<l)) d+=a[l+5+(5-k1)];}if(d.size()!=5) continue;
					out>?=cal(d);//cout<<d<<endl;
				}
			}
		}
		return out;
	}
};
