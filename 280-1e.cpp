//SRM280DIV1-250 CompletingBrackets
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
class CompletingBrackets{
	public:
	string CompletingBrackets::complete(string a){
		int x=0,y=0,i,n=a.size();string out="";
		for(i=0;i<n;i++){
			if(a[i]==']'){
				if(y<1) x++;else y--;
			}
			else y++;
		}
		for(i=0;i<x;i++) out+='[';out+=a;
		for(i=0;i<y;i++) out+=']';
		return out;
	}
};
