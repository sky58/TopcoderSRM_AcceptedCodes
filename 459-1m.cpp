//SRM459DIV1-500 NumberPyramids
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
int dp[1000100];
int mo=1000000009;
vector <int> com;
class NumberPyramids{
	public:
	int NumberPyramids::count(int a,int b){
		if(a>25) return 0;int i,j,k;
		memset(dp,0,sizeof(dp));dp[0]=1;com.pb(1);
		for(i=0;i<a-1;i++) com.pb(com[i]*(a-i-1)/(i+1));
		b-=(1<<(a-1));if(b<0) return 0;
		for(i=0;i<a;i++){
			for(j=com[i];j<=b;j++){
//				cout<<i<<' '<<j<<' '<<dp[j]<<endl;
				dp[j]=(dp[j]+dp[j-com[i]])%mo;
			}
		}
		return dp[b];
	}
};
