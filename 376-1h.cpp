//SRM376DIV1-1000 Unjumpers
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
int sol(string a){
	int b[3];int i,t=0;
	memset(b,0,sizeof(b));
	for(i=0;i<a.size();i++){
		if(a[i]=='*'){t++;b[i%3]++;}
	}
	if(t<1) return -1;
	return b[0]%2+b[1]%2*2+b[2]%2*4;
}
class Unjumpers{
	public:
	int Unjumpers::reachableTargets(string a,vector <string> b){
		int i,t=sol(a),out=0;
		for(i=0;i<b.size();i++){
			if(sol(b[i])==t || sol(b[i])+t==7) out++;
		}
		return out;
	}
};
