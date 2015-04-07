//SRM380DIV1-500 CompilingDecksWithJokers
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
class CompilingDecksWithJokers{
	public:
	int CompilingDecksWithJokers::maxCompleteDecks(vector <int> a,int b){
		int x=1100000000,y=0,i;
		while(x>y){
			int z=(x+y+1)/2,t=0;
			for(i=0;i<a.size();i++){
				t+=max(0,z-a[i]);
				if(t>z || t>b) break;
			}
			if(t>z || t>b) x=z-1;else y=z;
		}
		return x;
	}
};
