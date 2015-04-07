//SRM284DIV1-250 TriCount
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
lint inf=1000000000;
class TriCount{
	public:
	int TriCount::count(int A,int B){
		lint out=0,i,a=A,b=B;
		for(i=a;i<=b;i++){
			if(i<=b-i) out+=(b-i-i+1)*i+i*(i+1)/2;
			else out+=(b-i+2)*(b-i+1)/2;
			if(out>inf) return -1;
		}
		return (int)out;
	}
};
