//SRM450DIV1-250 OrderedNim
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
string na[2]={"Alice","Bob"};
class OrderedNim{
	public:
	string OrderedNim::winner(vector <int> a){
		int i,n=a.size();
		for(i=0;i<n;i++){if(a[i]>1) return na[i%2];}
		return na[(n+1)%2];
	}
};
