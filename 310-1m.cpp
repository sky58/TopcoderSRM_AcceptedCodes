//SRM310DIV1-500 FloatingMedian
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
template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
	typ sum(int a,int b){
		if(a==0){
			typ s=0;
			for(int i=b;i>=0;i=(i&(i+1))-1) s+=x[i];
			return s;
		}
		else return sum(0,b)-sum(0,a-1);
	}
	void add(int ind,typ f){
		for(int i=ind;i<x.size();i|=i+1) x[i]+=f;
	}
};
BIT <int> b(70000);int d;
class FloatingMedian{
	public:
	long long FloatingMedian::sumOfMedians(int seed,int mul,int add,int n,int k){
		int i;d=(k+1)/2;lint out=0;
		vector <lint> a;a.pb(seed);for(i=0;i<n-1;i++) a.pb((a[i]*mul+add)%65536);
		for(i=0;i<k;i++){
			b.add(a[i],1);
		}
		for(i=0;i<=n-k;i++){
			int x=-1,y=69000;
			while(y-x>1){
				int z=(x+y)/2;if(b.sum(0,z)<d) x=z;else y=z;
			}
			out+=y;
			if(i<n-k){
				b.add(a[i],-1);b.add(a[i+k],1);
			}
		}
		return out;
	}
};
