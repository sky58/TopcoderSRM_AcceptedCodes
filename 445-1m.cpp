//SRM445DIV1-550 TheLockDivOne
#include<stdio.h>
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
#include<list>
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
vector <lint> zyo;
lint kei(lint a){
	int i;
	if(a==0) return 0;if(a==1) return 1;
	for(i=0;i<55;i++){
		if(zyo[i]<=a && zyo[i+1]>a) break;
	}
	if(a-zyo[i]==0) return kei(a-1)+zyo[i];
	return zyo[i]+kei(a-zyo[i]-1);
}
lint dfs(lint a){
	int i;
	if(a==0) return 0;if(a==1) return 1;
	for(i=0;i<55;i++){
		if(zyo[i]<=a && zyo[i+1]>a) break;
	}
	if(a-zyo[i]==0) return kei(a-1)+zyo[i];
	return zyo[i]+max(kei(zyo[i]-1),dfs(a-zyo[i]-1));
}
class TheLockDivOne{
	public:
	string TheLockDivOne::password(int a,long long b){
		int i;zyo.pb(1);for(i=0;i<60;i++) zyo.pb(zyo[i]*2);
		lint s=dfs(b-1);string out;
		for(i=0;i<a;i++){
			out+=((s%2)+'0');s/=2;
		}
		reverse(out.begin(),out.end());
		return out;
	}
};
