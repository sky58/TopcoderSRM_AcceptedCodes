//SRM513DIV1-1000 Reflections
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
vector <vector <lint> > t;vector <lint> cl;
lint cal(lint a,vector <int> b){
	lint ret=abs(a);int i,j,n=b.size();if(n<1) return ret;
	for(i=0;i<25;i++) t[i].clear();
	for(i=0;i<(1<<n);i++){
		lint s=0;
		for(j=0;j<n;j++){
			if((i&(1<<j))) s+=2*b[j];
		}
		t[__builtin_popcount(i)].pb(s);
	}
	for(i=0;i<25;i++) sort(t[i].begin(),t[i].end());
	for(i=1;i<=n;i++){
		int x=(i+1)/2,y=i-x,it=0;
		for(j=0;j<t[x].size();j++){
			while(it<t[y].size()-1 && t[y][it]<t[x][j]-a) it++;
			ret<?=i+abs(t[x][j]-a-t[y][it]);
			if(it>0) ret<?=i+abs(t[x][j]-a-t[y][it-1]);
		}
	}
	return ret;
}
class Reflections{
	public:
	long long Reflections::minimumMoves(vector <int> x,vector <int> y,vector <int> z,vector <int> d){
		for(int i=0;i<25;i++) t.pb(cl);
		return cal((lint)d[0],x)+cal((lint)d[1],y)+cal((lint)d[2],z);
	}
};
