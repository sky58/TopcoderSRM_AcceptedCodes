//SRM254DIV1-250 ListeningIn
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
class ListeningIn{
	public:
	string ListeningIn::probableMatch(string a,string b){
		string out="";int i,t=0,n=a.size(),m=b.size();
		for(i=0;i<m;i++){
			if(a[t]==b[i]) t++;else out+=b[i];
		}
		if(t!=n) return "UNMATCHED";return out;
	}
};
