//SRM488DIV1-1000
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
class TheBoringGameDivOne{
	public:
	vector <int> TheBoringGameDivOne::find(int sj,int kj,int sb,int kb,int sf,int kf){
		vector <int> out;int inf=1000000,lo=inf,hi=0,a,b;
		if(kj+kb-sf!=kf-sj-sb) return out;
		for(a=0;a<=kf;a++) for(b=0;b+a<=kf;b++){
			if((kf+kj+kb+a+b)%2!=0) continue;
			int r=(kf+kj+kb+a+b)/2,wf=r-kf,hig=inf,low=0,h=max(0,sj-a),g=max(0,sb-b),e=h+a-sj,f=b+g-sb;
			hig<?=r-(h+a)-(b+g);low>?=e+f;hig<?=min(kj-g,kb-h);if(low<=wf && hig>=wf){hi>?=r;lo<?=r;}
		}
		if(lo>hi) return out;out.pb(lo);out.pb(hi);return out;
	}
};
