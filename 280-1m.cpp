//SRM280DIV1-500 GridCut
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
int cal(int w,int h,int n){
	if(n==0) return 0;
	int ret=1000000,i;
	if(n%w==0) ret<?=w;else ret<?=w+1;
	if(n%h==0) ret<?=h;else ret<?=h+1;
	for(i=1;i<=w && i<=h;i++){
		if(i*i>=n) ret<?=i*2;
		if(i<h || i<w) if(i*(i+1)>=n) ret<?=i*2+1;
	}
	return ret;
}
class GridCut{
	public:
	int GridCut::cutLength(int w,int h,int n){
		return min(cal(w,h,n),cal(w,h,w*h-n));
	}
};
