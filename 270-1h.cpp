//SRM270DIV1-900 PackingShapes
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
class PackingShapes{
	public:
	vector <string> PackingShapes::tryToFit(int W,int H,vector <string> a){
		vector <string> out;int w=max(W,H),h=min(W,H),i,x,y;string s;
		for(i=0;i<a.size();i++){
			istringstream sin(a[i]);sin>>s;
			if(s=="CIRCLE"){sin>>x;if(x*2<=h) out.pb("YES");else out.pb("NO");}
			else{
				sin>>x>>y;if(y>x){int d=y;y=x;x=d;}
				if(y<=h && x<=w) out.pb("YES");
				else{
					if(x==y) out.pb("NO");
					else{
						double b=1.0*y/x,c=(1.0*w-b*h)/(1.0-b*b);
						if(c<0.0 || c>=1.0*w) out.pb("NO");
						else{if(c*c+(1.0*h-b*c)*(1.0*h-b*c)>1.0*x*x-1e-10) out.pb("YES");else out.pb("NO");}
					}
				}
			}
		}
		return out;
	}
};
