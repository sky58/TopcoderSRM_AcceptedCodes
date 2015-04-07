//SRM532DIV1-300 DengklekMakingChains
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
//int left[55],right[55];
class DengklekMakingChains{
	public:
	int DengklekMakingChains::maxBeauty(vector <string> a){
		int all=0,out=0,ma=0,i,j,n=a.size();
		int left[55],right[55];
		memset(left,0,sizeof(left));memset(right,0,sizeof(right));
		rep(i,n){
			if(a[i][0]!='.' && a[i][1]!='.' && a[i][2]!='.'){
				all+=(a[i][0]-'0')+(a[i][1]-'0')+(a[i][2]-'0');
			}
			else{
				int x=0,y=0,z=0;
				rep(j,3){
					if(a[i][j]=='.') break;x+=(a[i][j]-'0');
				}
				for(j=2;j>=0;j--){
					if(a[i][j]=='.') break;y+=(a[i][j]-'0');
				}
				//rep(j,3) z+=(a[i][j]-'0');
				//left>?=x;right>?=y;
				rep(j,3){if(a[i][j]!='.') ma>?=(a[i][j]-'0');}
				left[i]=x;right[i]=y;
			}
		}
//		cout<<all<<' '<<left<<' '<<right<<endl;
		out>?=all;
		rep(i,n) out>?=max(left[i],right[i]);
		rep(i,n) rep(j,n){
			if(i==j) continue;out>?=all+left[i]+right[j];
		}
		return max(out,ma);
	}
};
