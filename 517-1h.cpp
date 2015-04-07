//SRM517DIV1-900 ColorfulBoard
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
bool gr[110][110];
int cal(vector <string> a){
	int h=a.size(),w=a[0].size(),out=1000,i,j,k,l;
	rep(i,h){
		int t=0;memset(gr,false,sizeof(gr));
		rep(j,h){
			if(a[i]==a[j]) continue;t++;
			rep(k,w){if(a[i][k]!=a[j][k]) break;}
			char row=a[j][k];
			rep(k,w){
				char col=a[i][k],now=a[j][k];
//				if(now!=col && now!=row) t=1000;
				if(now!=col) gr[h+k][j]=true;
				if(now!=row) gr[j][h+k]=true;
			}
		}
//		cout<<i<<' '<<t<<endl;
		rep(l,w+h) rep(j,w+h) rep(k,w+h){if(gr[j][l] && gr[l][k]) gr[j][k]=true;}
		rep(l,w+h){if(gr[l][l]) t=1000;}
		out<?=t+w;
	}
	return out;
}
class ColorfulBoard{
	public:
	int ColorfulBoard::theMin(vector <string> a){
		int h=a.size(),w=a[0].size(),out=1000,i,j;
		out<?=cal(a);
		vector <string> b;
		rep(i,w){
			string s="";rep(j,h) s+=a[j][i];b.pb(s);
		}
		a=b;out<?=cal(a);
		if(out>500) return -1;return out;
	}
};
