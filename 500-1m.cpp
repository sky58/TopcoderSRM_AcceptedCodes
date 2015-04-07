//SRM500DIV1-500 FractalPicture
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
double rec(int n,int x1,int y1,int x2,int y2){
//	cout<<n<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
//	int a=x1,b=y1,c=x2,d=y2;
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	double ret=0.0;
	if(n>=500){
		if(x1>0 || x2<0) return 0.0;y1>?=0;y2<?=81;return max(0,y2-y1)+0.0;
	}
	x1>?=-27;x2<?=27;y1>?=0;y2<?=81;
	if(x1>x2 || y1>y2) return 0.0;
	if(x2-x1>=54 && y2-y1>=81) return 81.0+54.0*(500-n);
	if(x1<=0 && x2>=0) ret+=max(0,min(54,y2)-y1);
	y1-=54;y2-=54;x1*=3;x2*=3;y1*=3;y2*=3;
	ret+=(rec(n+1,x1,y1,x2,y2)+rec(n+1,-y2,x1,-y1,x2)+rec(n+1,y1,-x2,y2,-x1))/3.0;
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<ret<<endl;
	return ret;
}
class FractalPicture{
	public:
	double FractalPicture::getLength(int x1,int y1,int x2,int y2){
		return rec(1,x1,y1,x2,y2);
	}
};
