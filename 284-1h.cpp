//SRM284DIV1-800 CantorSet
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
class CantorSet{
	public:
	int CantorSet::removed(string a){
		int i,j,n=a.size();
		vector <int> b;b.pb(0);for(i=1;i<n;i++) b.pb(a[i]-'0');
		for(int i=0;i<1000000;i++){
			int t=0;
			for(j=n-1;j>=0;j--){t+=b[j]*3;b[j]=t%10;t/=10;}
//			for(j=0;j<n;j++) cout<<b[j];cout<<endl;
			if(b[0]==1) return i+1;if(b[0]==2) b[0]-=2;
		}
		return 0;
	}
};
