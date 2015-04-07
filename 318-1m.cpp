//SRM318DIV1-600 CyclicGame
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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
double dp[20];
class CyclicGame{
	public:
	double CyclicGame::estimateBank(vector <int> a){
		int i,j,k,n=a.size();
		for(i=0;i<20;i++) dp[i]=0.0;
		for(i=0;i<500000;i++) for(j=0;j<n;j++){
			double f=0.0;
			for(k=1;k<=6;k++){f=f+dp[(j+k)%n]+a[(j+k)%n];}
			dp[j]>?=f/6.0;
		}
		return dp[0];
	}
};
