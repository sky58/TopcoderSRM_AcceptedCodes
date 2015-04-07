//SRM398DIV1-250 CountExpressions
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
#define All(s) s.begin(),s.end()
class CountExpressions{
	public:
	int CountExpressions::calcExpressions(int a,int b,int c){
		int out=0,i,j,k,t;vector <int> s;
		s.push_back(a);s.push_back(a);s.push_back(b);s.push_back(b);
		
		sort(All(s));
		do{
			for(i=0;i<27;i++){
				t=i,k=s[0];
				for(j=0;j<3;j++){
					if(t%3==0) k+=s[1+j];
					if(t%3==1) k-=s[1+j];
					if(t%3==2) k*=s[1+j];
					t/=3;
				}
				if(k==c) out++;
			}
		}while(next_permutation(All(s)));
		return out;
	}
};
