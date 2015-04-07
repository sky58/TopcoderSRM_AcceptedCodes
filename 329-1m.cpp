//SRM329DIV1-500 LogCutter
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
typedef long long lint;
#define pb push_back
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class LogCutter{
	public:
	string LogCutter::bestCut(int l,int a,int k,int c){
		int i,x=1,y=l,n,ret;
		vector <int> cut;
		for(i=1;i<=k;i++) cut.pb((int)(((lint)a*i)%(l-1))+1);
		cut.pb(0);cut.pb(l);sort(cut.begin(),cut.end());
		n=cut.size();
//		for(i=0;i<n;i++) cout<<cut[i]<<'\n';
		while(x<y){
			int now=0,z=(x+y)/2;
			for(i=0;i<=c;i++){
				int next=now;
				while(1){
					if(next==n-1) break;
					if(cut[next+1]-cut[now]>z) break;
					next++;
				}
				now=next;
			}
			if(now==n-1) y=z;else x=z+1;
		}
		reverse(cut.begin(),cut.end());
		int now=0;
		for(i=0;i<=c;i++){
			int next=now;
			while(1){
				if(next==n-1) break;
				if(cut[now]-cut[next+1]>x) break;
				next++;
			}
			if(next==n-1){
				if(i==c) ret=cut[now];
				else ret=cut[n-2];
				break;
			}
			now=next;
		}
		return moji(x)+" "+moji(ret);
	}
};
