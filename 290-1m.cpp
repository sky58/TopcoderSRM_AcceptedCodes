//SRM290DIV1-500 SnailRace
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
class SnailRace{
	public:
	double SnailRace::shortestTime(int n,int d,int s,int g){
		d--;n--;if(s>=g) return 1.0*d/s;
		double x=1.0*d/s/(2.0*n/(s+g)+1.0/s);return x/g+(1.0*d-x)/s;
	}
};
