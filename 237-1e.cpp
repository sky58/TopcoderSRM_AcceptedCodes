//SRM237DIV1-250 BoxUnion
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
int po[5][5];
int cal(int a,int b,int c,int d){
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	if(c>=b || a>=d) return 0;return min(min(d-a,b-c),min(b-a,d-c));
}
class BoxUnion{
	public:
	int BoxUnion::area(vector <string> e){
		int out=0,n=e.size(),i,j;
		for(i=0;i<n;i++){
			istringstream sin(e[i]);
			for(j=0;j<4;j++) sin>>po[i][j];
		}
		for(i=0;i<n;i++) out+=(po[i][2]-po[i][0])*(po[i][3]-po[i][1]);//cout<<out<<endl;
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			out-=(cal(po[i][0],po[i][2],po[j][0],po[j][2]))*(cal(po[i][1],po[i][3],po[j][1],po[j][3]));
		}
		if(n<3) return out;
		if(cal(po[0][0],po[0][2],po[1][0],po[1][2])*cal(po[0][1],po[0][3],po[1][1],po[1][3])<1) return out;
		int a=max(po[0][0],po[1][0]),b=max(po[0][1],po[1][1]),c=min(po[0][2],po[1][2]),d=min(po[0][3],po[1][3]);
		out+=cal(a,c,po[2][0],po[2][2])*cal(b,d,po[2][1],po[2][3]);
		return out;
	}
};
