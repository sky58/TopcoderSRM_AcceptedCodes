//SRM224DIV1-250 TwoTurtledoves
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
class TwoTurtledoves{
	public:
	int TwoTurtledoves::presentType(int a){
		int i,j;
		for(i=1;;i++){
			if(i*(i+1)/2>=a){
				for(j=i;j>0;j--){
					if(j>=a) return j;a-=j;
				}
			}
			a-=i*(i+1)/2;
		}
	}
};
