//SRM291DIV1-250 Snowflakes
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
int n;
int de(int a){
	if(a>=n) return a-n;return n-a-1;
}
class Snowflakes{
	public:
	vector <string> Snowflakes::flareOut(vector <string> a){
		n=a.size();vector <string> b,out;int i,j;
		for(i=0;i<n;i++){
			string c="";
			for(j=0;j<n;j++){
				if(j<=i) c+=a[i][j];else c+=a[j][i];
			}
			b.pb(c);
		}
		for(i=0;i<2*n;i++){
			string c="";
			for(j=0;j<2*n;j++) c+=b[de(i)][de(j)];
			out.pb(c);
		}
		return out;
	}
};
