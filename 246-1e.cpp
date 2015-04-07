//SRM246DIV1-250 PiCalculator
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
string b="141592653589793238462643383279";
class PiCalculator{
	public:
	string PiCalculator::calculate(int a){
		string out=b.substr(0,a);
		if(b[a]>'4'){
			if(b[a-1]=='9'){out[a-2]++;out[a-1]='0';}
			else out[a-1]++;
		}
		out="3."+out;return out;
	}
};
