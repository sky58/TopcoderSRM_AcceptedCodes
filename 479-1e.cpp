//SRM479DIV1-250 TheCoffeeTimeDivOne
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
class TheCoffeeTimeDivOne{
  public:
  long long TheCoffeeTimeDivOne::find(int n,vector <int> tea){
    int i,it=0;lint out=0;
    sort(tea.begin(),tea.end());reverse(tea.begin(),tea.end());
    for(i=0;i<tea.size();i+=7) out+=47+(lint)2*tea[i];
    for(i=n;i>0;i-=7){
      while(1){
        if(it>=tea.size()) break;if(tea[it]<i) break;it++;i--;
      }
      if(i<=0) break;out+=47+(lint)2*i;
    }
    out+=(lint)4*n;return out;
  }
};
