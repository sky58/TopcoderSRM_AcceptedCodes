//SRM268DIV1-250 CmpdWords
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
map<string,int> me;
class CmpdWords{
	public:
	int CmpdWords::ambiguous(vector <string> a){
		int n=a.size(),i,j,out=0;
		for(i=0;i<n;i++) me[a[i]]=1;
		for(i=0;i<n;i++) for(j=0;j<n;j++){
			if(i==j) continue;string s=a[i]+a[j];
			if(me[s]==1){out++;me[s]=2;}
			if(!me[s]) me[s]=1;
		}
		return out;
	}
};
