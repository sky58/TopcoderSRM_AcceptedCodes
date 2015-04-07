//SRM348DIV1-250 LostParentheses
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
class LostParentheses{
	public:
	int LostParentheses::minResult(string a){
		int out=0,now=0,now1=0,fl=0,i;
		for(i=0;i<a.size();i++){
			if(a[i]=='-'){
				if(fl==0) out+=now;else out-=now;now=0;fl=1;
			}
			else if(a[i]=='+'){
				if(fl==0) out+=now;else out-=now;now=0;
			}
			else{
				now*=10;now+=(a[i]-'0');
			}
		}
		if(fl==0) out+=now;else out-=now;
		return out;
	}
};
