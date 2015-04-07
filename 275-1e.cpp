//SRM275DIV1-250 InverseHaar1D
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
class InverseHaar1D{
	public:
	vector <int> InverseHaar1D::transform(vector <int> a,int b){
		int i,j,n=a.size();
		for(i=b;i>0;i--){
			vector <int> c;
			for(j=0;j<n/(1<<i);j++){c.pb((a[j]+a[j+n/(1<<i)])/2);c.pb((a[j]-a[j+n/(1<<i)])/2);}
			for(j=n/(1<<(i-1));j<n;j++) c.pb(a[j]);a=c;
		}
		return a;
	}
};
