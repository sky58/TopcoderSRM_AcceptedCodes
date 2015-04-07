//SRM309DIV1-250 ScoreRecomposition
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
class ScoreRecomposition{
	public:
	int ScoreRecomposition::minError(string a,int b){
		int n=a.size(),out=2000,i;string c="";for(i=1;i<=n;i++) c+=(i+'a');
		while(1){
			int t=0,s=0;
			for(i=0;i<n;i++){
				if(a[i]=='C') s+=(c[i]-'a');t>?=abs(i+1-(c[i]-'a'));
			}
			if(s==b) out<?=t;
			if(!next_permutation(c.begin(),c.end())) break;
		}
		if(out>1000) return -1;return out;
	}
};
