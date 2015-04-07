//SRM211DIV1-250 grafixCorrupt
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
int cal(string a,string b){
	int ret=0,i,n=a.size();
	rep(i,n){if(a[i]==b[i]) ret++;}return ret;
}
class grafixCorrupt{
	public:
	int grafixCorrupt::selectWord(vector <string> a,string b){
		int n=a.size(),out=-1,ma=0,i;
		rep(i,n){
			int f=cal(b,a[i]);
			if(f>ma){ma=f;out=i;}
			if(f==ma){
				//if(out>=0 && a[out]>a[i]) out=i;
			}
		}
		return out;
	}
};
