//SRM264DIV1-250 DivisibilityRules
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
class DivisibilityRules{
	public:
	int DivisibilityRules::similar(int a,int b){
		int out=0,i,j;
		for(i=2;i<a;i++){
			int f=1,x=1,y=1;
			for(j=0;j<1100;j++){
				x=(x*a)%b;y=(y*a)%i;if(x!=y) f=0;
			}
			out+=f;
		}
		return out;
	}
};
