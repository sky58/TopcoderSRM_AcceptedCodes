//SRM290DIV1-250 BrokenClock
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
class BrokenClock{
	public:
	int BrokenClock::fewestClicks(string a,string b){
		int h1=(a[0]-'0')*10+(a[1]-'0'),m1=(a[3]-'0')*10+(a[4]-'0');
		int h2=(b[0]-'0')*10+(b[1]-'0'),m2=(b[3]-'0')*10+(b[4]-'0');
		int h=(h2+120-h1)%24,m=(m2+120-(m1+h))%60;return h+m;
	}
};
