//SRM475DIV1-600 RabbitIncreasing
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
typedef pair<lint,lint> pint;
lint mo=1000000009,mo2=(1LL<<55);
pint pl(pint a,pint b){
  pint ret=mp(a.fi+b.fi,a.se+b.se);
  ret.fi+=ret.se/mo;ret.se%=mo;ret.fi%=mo2;
  return ret;
}
pint ke(pint a){
	if(a.fi%2>0) a.se+=mo;a.fi/=2;a.se/=2;
 	return a;
}
class RabbitIncreasing{
  public:
  int RabbitIncreasing::getNumber(vector <int> a,int b){
    int i,it=0;
    if(a[0]<=2) return 0;
    pint no0=mp(0,1),no1=mp(0,0),no2=mp(0,0);
    for(i=1;i<=b;i++){
      if(i>1){
        pint ne0=pl(no1,no2),ne1=no0,ne2=ne0;
        no0=ne0;no1=ne1;no2=ne2;
      }
      if(it<a.size()) if(i==a[it]){
      	it++;no2=mp(0,0);no1=ke(no1);
      }
//      cout<<no0.se<<' '<<no1.se<<' '<<no2.se<<endl;
    }
    return (int)((no0.se+no1.se+no2.se)%mo);
  }
};
