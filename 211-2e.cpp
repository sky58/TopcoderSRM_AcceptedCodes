//SRM211DIV2-300 grafixClick
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
class grafixClick{
	public:
	vector <int> grafixClick::checkSaveButton(vector <int> a,vector <int> b){
		int i,n=a.size();vector <int> out;
		for(i=0;i<n;i++){
			if(a[i]>=20 && a[i]<=39 && b[i]>=50 && b[i]<=99) out.pb(i);
		}
		return out;
	}
};
