//SRM414DIV1-250(DIV2-500) Embassy
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
class Embassy{
	public:
	int Embassy::visaApplication(vector <int> a,int b,int c){
		int out=1000000000,i,j,n=a.size();
		for(i=0;i<b;i++){
			int now=i;
			for(j=0;j<n;j++){now+=a[j];if(now%b>c) now=(now/b+1)*b;}
			out<?=now-i;
		}
		return out;
	}
};
