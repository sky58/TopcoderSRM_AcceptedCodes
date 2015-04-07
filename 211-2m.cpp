//SRM211DIV2-400 grafixCorrupt
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
class grafixCorrupt{
	public:
	int grafixCorrupt::selectWord(vector <string> a,string b){
		int ma=0,out=-1,i,j,n=a.size(),m=b.size();
		for(i=0;i<n;i++){
			int t=0;
			for(j=0;j<m;j++){if(a[i][j]==b[j]) t++;}
			if(t>ma){ma=t;out=i;}
		}
		return out;
	}
};
