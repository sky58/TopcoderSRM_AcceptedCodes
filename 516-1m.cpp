//SRM516DIV1-500 RowsOrdering
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
map<char,int> me;
class RowsOrdering{
  public:
  int RowsOrdering::order(vector <string> a){
    int n=a.size(),m=a[0].size(),i,j;lint t=1,out=0,mo=1000000007;
    vector <lint> c;
    for(i=0;i<m;i++){
      me.clear();vector <lint> b;lint ret=0;
      for(j=0;j<n;j++) me[(a[j][i])]+=1;
      map<char,int>::iterator it=me.begin();
      while(it!=me.end()){
        b.pb((*it).second);it++;
      }
      sort(b.begin(),b.end());reverse(b.begin(),b.end());
      for(j=0;j<b.size();j++){
        ret=(ret+(j*b[j]))%mo;
      }
      c.pb(ret);
    }
    sort(c.begin(),c.end());
    for(i=0;i<m;i++) out=(out*50+c[i])%mo;
    return (int)((out+n)%mo);
  }
};
