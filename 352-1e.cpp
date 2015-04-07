//SRM352DIV1-250 NumberofFiboCells
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
class NumberofFiboCalls{
	public:
	vector <int> NumberofFiboCalls::fiboCallsMade(int n){
		int one[50],zero[50];int i;
		for(i=0;i<50;i++){one[i]=0;zero[i]=0;}zero[0]=1;one[1]=1;
		for(i=2;i<=40;i++){
			one[i]=one[i-1]+one[i-2];
			zero[i]=zero[i-1]+zero[i-2];
		}
		vector <int> out;out.push_back(zero[n]);out.push_back(one[n]);
		return out;
	}
};
