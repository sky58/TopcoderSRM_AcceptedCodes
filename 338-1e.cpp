//SRM338DIV1-250 ImprovingStatistics
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
#define Int long long
class ImprovingStatistics{
	public:
	int ImprovingStatistics::howManyGames(int a,int b){
		Int c=(Int)b*100/a;if(c>98) return -1;Int g;
		c++;
		Int n=a-b,t=100-c;
//		cout<<n<<' '<<t;
		if(n*100%t==0) g=n*100/t;
		else g=n*100/t+1;
		return (int)g-a;
	}
};
