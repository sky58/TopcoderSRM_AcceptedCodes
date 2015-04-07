//SRM567DIV1-500 StringGame
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int num[55][30];
bool st[55],ch[30];
int n;
bool cal(int t){
	memset(st,false,sizeof(st));
	memset(ch,false,sizeof(ch));
	int i,j,k;
	rep(i,26){
		rep(j,26){
			if(ch[j]) continue;
			int ma=0;
			rep(k,n){
				if(k==t || st[k]) continue;ma>?=num[k][j];
			}
			if(ma>num[t][j]) continue;
			rep(k,n){
				if(num[k][j]<num[t][j]) st[k]=true;
			}
			ch[j]=true;
		}
	}
	rep(i,n){
		if(i!=t && !st[i]) return false;
	}
	return true;
}
class StringGame{
	public:
	vector <int> StringGame::getWinningStrings(vector <string> a){
		n=a.size();
		int i,j,m=a[0].size();vector <int> out;
		memset(num,0,sizeof(num));
		rep(i,n) rep(j,m) num[i][(a[i][j]-'a')]++;
		rep(i,n){
			if(cal(i)) out.pb(i);
		}
		return out;
	}
};
