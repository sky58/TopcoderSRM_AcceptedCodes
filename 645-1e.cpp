//SRM645DIV1-250 JanuszTheBusinessman
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
bool sumi[58];
class JanuszTheBusinessman{
	public:
	int makeGuestsReturn(vector<int> a,vector<int> b){
		int n=a.size();
		memset(sumi,false,sizeof(sumi));
		for(int i=0;;i++){
			int mi=114514,ma=0;
			rep(j,n){
				if(!sumi[j]) mi=min(mi,b[j]);
			}
			if(mi>=114514) return i;
			rep(j,n){
				if(a[j]<=mi) ma=max(ma,b[j]);
			}
			rep(j,n){
				if(a[j]<=ma) sumi[j]=true;
			}
		}
		return n;
	}
};
