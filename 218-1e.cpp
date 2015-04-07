//SRM218DIV1-200 FolderSize
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
class FolderSize{
	public:
	vector <int> FolderSize::calculateWaste(vector <string> a,int b,int c){
		int n=a.size(),i,x,y;
		vector <int> out;rep(i,b) out.pb(0);
		rep(i,n){
			istringstream sin(a[i]);sin>>x>>y;y%=c;if(y>0) y=c-y;out[x]+=y;
		}
		return out;
	}
};
