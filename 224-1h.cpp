//SRM223DIV1-900 ArithSeq
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
class ArithSeq{
	public:
	long long ArithSeq::minStart(int n,int d){
		lint i,j;
		for(i=1;;i++){
			lint lo=(i-1)*i+1,hi=i*i;
			for(j=1;j<n;j++){
				lint s=(lint)sqrt(lo+j*d-1)+1;
				lo>?=s*(s-1)+1-j*d;hi<?=s*s-j*d;
				if(lo>hi) break;
			}
			if(lo<=hi) return lo;
		}
	}
};
