//SRM499DIV1-250 ColorfulRabbits
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
int ka[1100000];
class ColorfulRabbits{
	public:
	int ColorfulRabbits::getMinimum(vector <int> a){
		memset(ka,0,sizeof(ka));int i,out=0;
		for(i=0;i<a.size();i++) ka[a[i]]++;
		for(i=0;i<1050000;i++){
			if(ka[i]>0) out+=((ka[i]-1)/(i+1)+1)*(i+1);
		}
		return out;
	}
};
