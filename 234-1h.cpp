//SRM234DIV1-850 HowUnsorted
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
lint mergecount(vector<lint> &a) {
  lint count = 0;
  int n = a.size();
  if (n > 1) {
    vector<lint> b(a.begin(), a.begin() + n/2);
    vector<lint> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}
class HowUnsorted{
	public:
	long long HowUnsorted::howMany(int m,int c,int n){
		vector <lint> a;a.pb(1);int i,mo=(1<<31)-1;
		for(i=0;i<n-1;i++) a.pb((a[i]*m+c)%mo);
		return mergecount(a);
	}
};
