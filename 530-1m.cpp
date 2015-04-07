//SRM530DIV1-500 GogoXMarisaKirisima
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
bool aru[55];
class GogoXMarisaKirisima{
	public:
	int GogoXMarisaKirisima::solve(vector <string> a){
		vector <string> b=a;int i,j,k,n=a.size(),e=0,v=0;
		memset(aru,false,sizeof(aru));
		rep(i,n) b[i][i]='Y';
		rep(i,n) rep(j,n) rep(k,n){
			if(b[j][i]=='Y' && b[i][k]=='Y') b[j][k]='Y';
		}
		if(b[0][n-1]=='N') return 0;
		rep(i,n) rep(j,n){
			if(a[i][j]=='Y'){
				if(b[0][i]!='Y' || b[j][n-1]!='Y') continue;
				e++;aru[i]=aru[j]=true;
			}
		}
		rep(i,n){if(aru[i]) v++;}return e-v+2;
	}
};
