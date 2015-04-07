//SRM252DIV1-250 PermutationSum
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
class PermutationSum{
	public:
	int PermutationSum::add(int a){
		int out=0,i;vector <int> b;
		while(a>0){b.pb(a%10);a/=10;}
		sort(b.begin(),b.end());
		do{
			int t=0;for(i=0;i<b.size();i++) t=t*10+b[i];out+=t;
		}while(next_permutation(b.begin(),b.end()));
		return out;
	}
};
