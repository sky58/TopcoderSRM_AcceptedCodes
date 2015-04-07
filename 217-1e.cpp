//SRM217DIV1-250 PlayGame
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
class PlayGame{
	public:
	int PlayGame::saveCreatures(vector <int> a,vector <int> b){
		int n=a.size(),i,j,out=0,it=0;
		sort(All(a));sort(All(b));a.pb(1100);
		rep(i,n){
			while(a[it]<=b[i]) it++;if(it>=n) break;it++;
		}
		reverse(All(a));REP(j,1,i+1) out+=a[j];return out;
	}
};
