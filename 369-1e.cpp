//SRM369DIV1-250(DIV2-500) BeautifulString
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
using namespace std;
class BeautifulString{
	public:
	int BeautifulString::maximumLength(int a,int b,int ma,int mb){
		if(mb==0) return min(a,ma);
		if(ma==0) return min(b,mb);
		if(a<b) return a+(int)min((long long)b,(long long)mb*(a+1));
		return b+(int)min((long long)a,(long long)ma*(b+1));
	}
};
