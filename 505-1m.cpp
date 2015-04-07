//SRM505DIV1-500 SetMultiples
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
//int dp[110000];
class SetMultiples{
  public:
  long long SetMultiples::smallestSubset(long long a,long long b,long long c,long long d){
    lint con=100000,mi=1000000000000LL,i,out=0;
//    if(a>d/2) return 0;if(a==d/2) return 1;
//    if(b>=d/2) b=d/2;
	a>?=b/2+1;
    for(i=2;i<=con;i++){
      lint lo=(c-1)/i+1,hi=d/i;hi<?=mi-1;//cout<<min(b,hi)<<' '<<max(a,lo)<<endl;
//      cout<<out<<endl;
      out+=max(0LL,min(b,hi)-max(a,lo)+1);
      mi=lo;
    }
    for(i=a;i<mi && i<=b;i++){
      lint lo=(c-1)/i+1,hi=d/i;if(lo<=hi) out++;
    }
//    cout<<out<<endl;
    return (b-a+1-out)+min(d-d/2,d-c+1);
  }
};
