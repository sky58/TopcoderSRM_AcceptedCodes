//SRM487DIV1-250 BunnyComputer
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
int dp[55];
class BunnyComputer{
  public:
  int BunnyComputer::getMaximum(vector <int> a,int b){
    int i,n=a.size(),out=0,j;
    for(i=0;i<=b;i++){
      memset(dp,0,sizeof(dp));
      for(j=0;(j+1)*(b+1)+i<n;j++){dp[j+1]>?=dp[j];dp[j+2]>?=dp[j]+a[j*(b+1)+i]+a[(j+1)*(b+1)+i];}
      out+=max(dp[j],dp[j+1]);
    }
    return out;
  }
};
