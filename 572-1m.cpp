//SRM572DIV1-500 getNumber
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
map<vector<int>,int> ma;
int zyo[7];
class EllysBulls{
	public:
	string getNumber(vector<string> a,vector<int> b){
		int n=a[0].size(),m=a.size(),x=n/2,y=n-x,ze,out=0;
		zyo[0]=1;rep(i,6) zyo[i+1]=10*zyo[i];
		vector<int> de;
		rep(i,zyo[y]){
			int z=i;
			vector<int> t(m,0);
			rep(j,y){
				int w=z%10;z/=10;
				rep(k,m){
					if((a[k][x+j]-'0')==w) t[k]++;
				}
			}
			ma[t]++;
		}
		rep(i,zyo[x]){
			int z=i;
			vector<int> t=b;
			rep(j,x){
				int w=z%10;z/=10;
				rep(k,m){
					if((a[k][j]-'0')==w) t[k]--;
				}
			}
			int num=ma[t];
			if(num>0) ze=i,de=t;
			out+=num;
		}
		if(out==0) return "Liar";
		if(out>1) return "Ambiguity";
		string ret="";
		rep(i,x){
			ret+=((ze%10)+'0');ze/=10;
		}
		rep(i,zyo[y]){
			int z=i;
			vector<int> t(m,0);
			rep(j,y){
				int w=z%10;z/=10;
				rep(k,m){
					if((a[k][x+j]-'0')==w) t[k]++;
				}
			}
			if(t==de){
				rep(j,y){
					ret+=((i%10)+'0');i/=10;
				}
				break;
			}
		}
		return ret;
	}
};
