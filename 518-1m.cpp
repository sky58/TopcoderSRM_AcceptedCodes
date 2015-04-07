//SRM518DIV1-500 ConvexSequence
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
class ConvexSequence{
	public:
	long long ConvexSequence::getMinimum(vector <int> a){
		int n=a.size(),i;lint out=0;
		while(1){
			int f=0;
			REP(i,1,n-1){
				if(2*a[i]>a[i+1]+a[i-1]){
					int k=(2*a[i]-a[i-1]-a[i+1]+1)/2;out+=k;a[i]-=k;f=1;
				}
			}
			if(f<1) break;
		}
		return out;
	}
};
