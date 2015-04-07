//SRM321DIV1-250 Chocolate
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
class Chocolate{
	public:
	int Chocolate::minSplitNumber(int x,int y,int s){
		int i,out=10;
		for(i=1;i*i<=s;i++){
			if(s%i!=0) continue;
			int c=s/i;
			if(x==i && y==c) out<?=0;
			if(x==c && y==i) out<?=0;
			if(x==i && y>c) out<?=1;
			if(x==c && y>i) out<?=1;
			if(x>c && y==i) out<?=1;
			if(x>i && y==c) out<?=1;
			if(x>c && y>i) out<?=2;
			if(x>i && y>c) out<?=2;
		}
		if(out>5) return -1;return out;
	}
};
