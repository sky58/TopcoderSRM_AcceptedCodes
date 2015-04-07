//SRM296DIV1-250 NewAlbum
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
class NewAlbum{
	public:
	int NewAlbum::leastAmountOfCDs(int a,int c,int b){
		int d=(b+1)/(c+1);if(d%13==0) d--;
		int e=a/d,f=a%d;
		if(f==0) return e;
		if(f%13==0){
			if(e==0) return 2;
			if(d-f==1) return e+2;
		}
		return e+1;
	}
};
