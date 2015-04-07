//SRM236DIV1-500 HammingNumbers
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
priority_queue<int> t;
//map<lint,int> memo;
class HammingNumbers{
	public:
	int HammingNumbers::getNumber(vector <int> a,int b){
//		memo[1]=1;
		t.push(-1);lint ma=2147483647LL,be=0;int i,j,n=a.size();
		for(i=0;i<b;i++){
			if(t.empty()) return -1;lint f=-t.top();t.pop();
			while(f==be){if(t.empty()) return -1;f=-t.top();t.pop();}be=f;
			if(i==b-1) return f;
			for(j=0;j<n;j++){
//				lint x=a[j]*f;if(!memo[x]){memo[x]=1;t.push(-x);}
				if(a[j]*f<=ma)t.push(-(int)(a[j]*f));
			}
		}
	}
};
