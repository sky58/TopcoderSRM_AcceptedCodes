//SRM267DIV1-500 ValetParking
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
class ValetParking{
	public:
	int ValetParking::minMoves(int ex,int ey,int cx,int cy){
		if(cx==0 && cy==0) return 0;int out=100000000;
		if(cx>0){
			int d=abs(ex-(cx-1))+abs(ey-cy),x=cx,y=cy;if(ey==cy && cx-1<ex) d+=2;x--;d++;
			while(1){
				if(y<1) break;y--;d+=3;
				if(x<1) break;x--;d+=3;
			}
			out<?=d+max(x,y)*5;
		}
		if(cy>0){
			int d=abs(ex-cx)+abs(ey-(cy-1)),x=cx,y=cy;if(ex==cx && cy-1<ey) d+=2;y--;d++;
			while(1){
				if(x<1) break;x--;d+=3;
				if(y<1) break;y--;d+=3;
			}
			out<?=d+max(x,y)*5;
		}
		return out;
	}
};
