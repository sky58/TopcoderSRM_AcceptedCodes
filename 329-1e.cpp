//SRM329DIV1-250 RailroadSeatNumeration
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
int b[4]={1,3,4,6};
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class RailroadSeatNumeration{
	public:
	string RailroadSeatNumeration::getInternational(vector <int> a){
		string out;int i,n=a.size(),l=3;
		for(i=0;i<n;i++){
			int c=0;
			if(a[i]<37) c++;
			if(a[i]/10<10 && a[i]/10>0 && (a[i]%10==1 || a[i]%10==3 || a[i]%10==4 || a[i]%10==6)) c+=2;
//			if(c==0) return "BAD DATA";if(c==3) return "AMBIGUOUS";
//			if(c>1) out+=moji(a[i]);if(c==1){out+=(((a[i]-1)/4+1)+'0');out+=(b[(a[i]-1)%4]+'0');}
			l=l&c;
		}
		if(l==0) return "BAD DATA";if(l==3) return "AMBIGUOUS";
		for(i=0;i<n;i++){
			if(l==2) out+=moji(a[i]);if(l==1){out+=(((a[i]-1)/4+1)+'0');out+=(b[(a[i]-1)%4]+'0');}
			if(i<n-1) out+=' ';
		}
		return out;
	}
};
