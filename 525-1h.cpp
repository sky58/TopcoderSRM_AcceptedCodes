//SRM525DIV1-950 MonochromePuzzle
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
bool su[55],sumi[55];
int p[55];
class MonochromePuzzle{
	public:
	int MonochromePuzzle::getMinimum(vector <string> a){
		int n=a.size(),inf=10000,out=inf,i,j;
		rep(i,n){if(a[i][i]=='#') return -1;}
		rep(i,n) rep(j,n){if(a[i][j]!=a[j][i]) return -1;}
		rep(i,n){
			int t=0;rep(j,n){if(a[i][j]=='#') t++;}if(t!=3) return -1;
		}
		rep(p[0],n) rep(p[1],n) rep(p[n-1],n){
			if(a[p[0]][p[1]]=='.' || a[p[0]][p[n-1]]=='.') continue;
			memset(sumi,false,sizeof(sumi));REP(i,2,n-1) p[i]=-1;
			sumi[p[0]]=sumi[p[1]]=sumi[p[2]]=true;int f=0;
			rep(i,n){
				if(!sumi[i] && a[i][p[1]]=='#' && a[i][p[n-1]]=='#'){p[n-2]=i;sumi[i]=true;}
			}
			if(p[n-2]<0) continue;
			rep(i,n/2-2){
				rep(j,n){
					if(!sumi[j] && a[j][p[i+1]]=='#'){p[i+2]=j;sumi[j]=true;}
				}
				if(p[i+2]<0){f=1;break;}
				rep(j,n){
					if(!sumi[j] && a[j][p[i+2]]=='#' && a[j][p[n-i-2]]=='#'){p[n-i-3]=j;sumi[j]=true;}
				}
				if(p[n-i-3]<0){f=1;break;}
			}
			if(f>0) continue;
			if(a[p[n/2-1]][p[0]]=='.' || a[p[n/2]][p[n-1]]=='.') continue;
			memset(su,false,sizeof(su));int t=0;
			rep(i,n){
				int now=i;
				if(su[i]) continue;su[i]=true;
				while(p[now]!=i){now=p[now];t++;su[now]=true;}
			}
//			rep(i,n) cout<<p[i]<<' ';cout<<t<<endl;
			out<?=t;
		}
		if(out>=inf) return -1;return out;
	}
};
