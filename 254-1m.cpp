//SRM254DIV1-500 Piglets
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
class Piglets{
	public:
	int Piglets::choose(string a){
		int n=a.size(),i;
		if(a[0]=='-') return 0;if(a[n-1]=='-') return n-1;
		for(i=n-1;i>=1;i--){
			if(a[i]=='-' && a[i-1]=='-') return i-1;
		}
		for(i=0;i<n;i++){
			if(a[i]=='-') return i;
		}
		return -1;
	}
};
