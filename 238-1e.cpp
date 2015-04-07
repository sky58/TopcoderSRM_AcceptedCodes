//SRM238DIV1-200 PrintScheduler
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
int now[55];
class PrintScheduler{
	public:
	string PrintScheduler::getOutput(vector <string> a,vector <string> b){
		int i,j,x,y;
		memset(now,0,sizeof(now));string out="";
		for(i=0;i<b.size();i++){
			istringstream sin(b[i]);sin>>x>>y;
			for(j=0;j<y;j++){out+=a[x][now[x]%a[x].size()];now[x]++;}
		}
		return out;
	}
};
