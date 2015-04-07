//SRM473DIV1-500 RightTriangle
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
bool te[1100000];
int aru[1100000];
class RightTriangle{
	public:
	long long RightTriangle::triangleCount(int p,int n,int a,int b,int c){
		if(p%2!=0) return 0;lint out=0;int i,no=0;
		memset(aru,0,sizeof(aru));
		for(i=0;i<n;i++){
			lint pn=(lint)a*i*i+(lint)b*i+c;
/*			while(1){
				if(!te[(int)(pn%p)]){te[(int)(pn%p)]=true;break;}pn++;
			}
*/			aru[pn%p]++;
		}
		for(i=0;i<5*p;i++){
			no+=aru[i%p];aru[i%p]=0;if(no>0 && !te[i%p]){te[i%p]=true;no--;}
		}
		for(i=0;i<p/2;i++){
			if(te[i] && te[i+p/2]) out+=(n-2);
		}
		return out;
	}
};
