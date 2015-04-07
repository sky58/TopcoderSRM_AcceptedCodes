//SRM297DIV1-250 OptimalQueues
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
class OptimalQueues{
	public:
	int OptimalQueues::minWaitingTime(vector <int> a,int b,int c){
		sort(a.begin(),a.end());reverse(a.begin(),a.end());int i,out=0;
		for(i=0;i<a.size();i++) out>?=a[i]+(i/b)*c+c;return out;
	}
};
