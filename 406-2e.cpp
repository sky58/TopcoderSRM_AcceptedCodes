//SRM406DIV2-250 HappyCells
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
int dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};
class HappyCells{
	public:
	vector <int> HappyCells::getHappy(vector <string> a){
		int n=a.size(),m=a[0].size(),i,j,k;
		vector <int> out;out.pb(0);out.pb(0);out.pb(0);
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			int s=0,t=0;if(a[i][j]=='X') continue;
			for(k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x>=0 && y>=0 && x<n && y<m) if(a[x][y]=='.') s=1;
			}
			for(k=4;k<8;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x>=0 && y>=0 && x<n && y<m) if(a[x][y]=='.') t=1;
			}
			if(s==0 && t==0) out[0]++;else if(s==0) out[1]++;else if(t==0) out[2]++;
		}
		return out;
	}
};
