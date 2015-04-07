//SRM457DIV1-500 TheHexagonsDivOne
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
class TheHexagonsDivOne{
	public:
	long long TheHexagonsDivOne::count(int a){
		lint per[10];per[1]=a;
		for(int i=1;i<8;i++) per[i+1]=per[i]*(a-i);
		return (per[4]*16*4+per[5]*32*18+per[6]*64*9+per[7]*128)/6;
	}
};
