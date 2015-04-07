//SRM381DIV1-250 TheDiceGame
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
class TheDiceGame{
	public:
	double TheDiceGame::expectedThrows(int n){
		double dp[1100000];dp[1]=1;dp[0]=0;
		for(int i=2;i<=n;i++){
			double t=0.0;
			for(int j=1;j<=6;j++) t+=dp[max(0,i-j)];
			t/=6;dp[i]=t+1;
		}
		return dp[n];
	}
};
