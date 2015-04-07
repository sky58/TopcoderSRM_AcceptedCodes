//SRM260DIV1-250 GridPointOnCircle
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
map<int,int> me;vector <int> a;
class GridPointsOnCircle{
	public:
	int GridPointsOnCircle::countPoints(int n){
		int i,out=0;
		for(i=0;i*i<=n;i++){a.pb(i*i);me[i*i]=1;}
		for(i=0;i<a.size();i++){
			int t=1;
			if(me[n-a[i]]){
				if(a[i]>0) t*=2;if(n-a[i]>0) t*=2;out+=t;
			}
		}
		return out;
	}
};
