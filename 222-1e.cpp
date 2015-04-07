//SRM222DIV1-250 GroceryBagger
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
map<string,int> me;
class GroceryBagger{
	public:
	int GroceryBagger::minimumBags(int a,vector <string> b){
		int i,out=0;
		for(i=0;i<b.size();i++) me[b[i]]++;
		map<string,int>::iterator it=me.begin();
		while(it!=me.end()){
			out+=((*it).se-1)/a+1;it++;
		}
		return out;
	}
};
