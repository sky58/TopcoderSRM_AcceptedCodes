//SRM319DIV1-1000 Manhattan
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
vector <int> ans(int A,int B){
	vector <int> ret;
	if(A==0 && B==0){
		ret.pb(0);ret.pb(1);return ret;
	}
	int a=min(A,B),b=max(A,B);
	ret.pb(a);ret.pb(b);return ret;
}
class Manhattan{
	public:
	vector <int> Manhattan::furthestPair(int n,int a,int b,int m){
		vector <lint> po;po.pb(0);lint max1=-2010000000,max2=max1,min1=2010000000,min2=min1;
		int max1i=0,max2i=0,min1i=0,min2i=0,i;
		for(i=0;i<2*n-1;i++) po.pb((po[i]*a+b)%m);
		for(i=0;i<2*n;i+=2){
			if(max1<po[i]+po[i+1]){max1=po[i]+po[i+1];max1i=i/2;}
			if(min1>po[i]+po[i+1]){min1=po[i]+po[i+1];min1i=i/2;}
			if(max2<po[i]-po[i+1]){max2=po[i]-po[i+1];max2i=i/2;}
			if(min2>po[i]-po[i+1]){min2=po[i]-po[i+1];min2i=i/2;}
		}
		if(max1-min1>max2-min2) return ans(max1i,min1i);
		if(max1-min1<max2-min2) return ans(max2i,min2i);
		if(min(max1i,min1i)<min(max2i,min2i)) return ans(max1i,min1i);
		if(min(max1i,min1i)>min(max2i,min2i)) return ans(max2i,min2i);
		if(max(max1i,min1i)<max(max2i,min2i)) return ans(max1i,min1i);
		return ans(max2i,min2i);
	}
};
