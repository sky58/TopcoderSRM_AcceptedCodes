//SRM212DIV1-250 WinningRecord
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
class WinningRecord{
	public:
	vector <int> WinningRecord::getBestAndWorst(string a){
		int out1=1,w1=0,out2=1,w2=1,i,win=0,n=a.size();
		REP(i,1,n+1){
			if(a[i-1]=='W') win++;
			if(i>2){
				if(win*out1>=i*w1){out1=i;w1=win;}
				if(win*out2<=i*w2){out2=i;w2=win;}
			}
		}
		vector <int> out;out.pb(out1);out.pb(out2);return out;
	}
};
