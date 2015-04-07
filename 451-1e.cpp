//SRM451DIV1-250 MagicalSource
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
class MagicalSource{
	public:
	long long MagicalSource::calculate(long long a){
		lint out=a,b=11;
		while(a>=b){
			if(a%b==0) out=a/b;b=b*10+1;
		}
		return out;
	}
};
