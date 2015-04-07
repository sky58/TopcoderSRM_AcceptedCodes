//SRM358DIV1-500 BrokenBottons
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
bool bor[10];
int keta(int a){
	if(a==100) return 0;
	if(a==0){
		if(bor[0]) return 10000000;
		else return 1;
	}
	int ret=0;
	while(a>0){
		if(bor[a%10]) return 10000000;
		a/=10;ret++;
	}
	return ret;
}
class BrokenButtons{
	public:
	int BrokenButtons::minPresses(int a,vector <int> b){
		int i,out=10000000;
		for(i=0;i<10;i++) bor[i]=false;
		for(i=0;i<b.size();i++) bor[b[i]]=true;
		
		for(i=0;i<1000000;i++){
			out=min(out,abs(i-a)+keta(i));
		}
		return out;
	}
};
