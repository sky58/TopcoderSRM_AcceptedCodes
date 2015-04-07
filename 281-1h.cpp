//SRM281DIV1-1000 Equidistance
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
vector <lint> a;int n;
lint cal(int t,lint d){
	lint ret=0;
	for(int i=0;i<n;i++) ret+=abs((a[t]+d*(i-t))-a[i]);
	return ret;
}
class Equidistance{
	public:
	long long Equidistance::minimumEffort(vector <int> A){
		n=A.size();lint out=8000000000000000000LL,i,j;
		for(i=0;i<n;i++) a.pb(A[i]);sort(a.begin(),a.end());
		for(i=0;i<n;i++){
			lint x=1,y=10000000000LL;
			while(y-x>5){
				lint z=(x*2+y)/3,w=(x+y*2)/3;
				if(cal(i,z)<cal(i,w)) y=w;else x=z;
			}
			for(j=x;j<=y;j++) out<?=cal(i,j);
		}
		return out;
	}
};
