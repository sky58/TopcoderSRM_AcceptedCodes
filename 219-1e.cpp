//SRM219DIV1-250 HealthFood
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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class HealthFood{
	public:
	vector <int> HealthFood::selectMeals(vector <int> p,vector <int> c,vector <int> f,vector <string> a){
		int n=p.size(),i,j,k;
		vector <int> t,out;
		rep(i,n) t.pb(p[i]*5+c[i]*5+f[i]*9);
		rep(i,a.size()){
			int ret=0;
			REP(j,1,n){
				rep(k,a[i].size()){
					if(a[i][k]=='p'){
						if(p[ret]>p[j]){ret=j;break;}
						if(p[ret]<p[j]) break;
					}
					if(a[i][k]=='P'){
						if(p[ret]<p[j]){ret=j;break;}
						if(p[ret]>p[j]) break;
					}
					if(a[i][k]=='c'){
						if(c[ret]>c[j]){ret=j;break;}
						if(c[ret]<c[j]) break;
					}
					if(a[i][k]=='C'){
						if(c[ret]<c[j]){ret=j;break;}
						if(c[ret]>c[j]) break;
					}if(a[i][k]=='f'){
						if(f[ret]>f[j]){ret=j;break;}
						if(f[ret]<f[j]) break;
					}
					if(a[i][k]=='F'){
						if(f[ret]<f[j]){ret=j;break;}
						if(f[ret]>f[j]) break;
					}if(a[i][k]=='t'){
						if(t[ret]>t[j]){ret=j;break;}
						if(t[ret]<t[j]) break;
					}
					if(a[i][k]=='T'){
						if(t[ret]<t[j]){ret=j;break;}
						if(t[ret]>t[j]) break;
					}
				}
			}
			out.pb(ret);
		}
		return out;
	}
};
