//SRM323DIV1-250 RoodsAndFools
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
class RoadsAndFools{
	public:
	string RoadsAndFools::determineOrientation(int a,vector <int> b){
		int i,n=b.size();string out="";b[0]=min(b[0],a-b[0]);
		for(i=1;i<n;i++){
			if(min(b[i],a-b[i])>b[i-1]) b[i]=min(b[i],a-b[i]);
			else if(max(b[i],a-b[i])<=b[i-1]) return "NO SOLUTION";
			else b[i]=max(b[i],a-b[i]);
		}
		if(n>1) if(b[0]*2!=a && a-b[0]<b[1]) return "MULTIPLE SOLUTIONS";
		if(b[n-1]*2<a) return "MULTIPLE SOLUTIONS";
		for(i=1;i<n-1;i++){
			if(min(b[i],a-b[i])>b[i-1] && max(b[i],a-b[i])<b[i+1] && min(b[i],a-b[i])<max(b[i],a-b[i])) return "MULTIPLE SOLUTIONS";
		}
		for(i=0;i<n-1;i++) out+=(moji(b[i])+' ');out+=moji(b[n-1]);return out;
	}
};
