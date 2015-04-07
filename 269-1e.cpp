//SRM269DIV1-250 PatternOptimizer
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
class PatternOptimizer{
	public:
	string PatternOptimizer::optimize(string a){
		string out="";int i,t=0,s=0,j;
		for(i=0;i<a.size();i++){
			if(a[i]=='*') t++;
			else if(a[i]=='?') s++;
			else{
				if(t>0) out+='*';for(j=0;j<s;j++) out+='?';t=0;s=0;
				out+=a[i];
			}
		}
		if(t>0) out+='*';for(j=0;j<s;j++) out+='?';
		return out;
	}
};
