//SRM477DIV1-250 Islands
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
int dy1[6]={-1,0,-1,1,-1,0};
int dy2[6]={1,0,-1,1,1,0};
int dx[6]={-1,-1,0,0,1,1};
class Islands{
	public:
	int Islands::beachLength(vector <string> a){
		int i,j,k,out=0,n=a.size(),m=a[0].size();
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='#'){
				if(i%2==0){
					for(k=0;k<6;k++){
						int x=i+dx[k],y=j+dy1[k];
//						cout<<x<<' '<<y<<endl;
						if(x<0 || x>=n || y<0 || y>=m) continue;
						if(a[x][y]=='.') out++;
					}
				}
				else{
					for(k=0;k<6;k++){
						int x=i+dx[k],y=j+dy2[k];
						if(x<0 || x>=n || y<0 || y>=m) continue;
						if(a[x][y]=='.') out++;
					}
				}
			}
		}
		return out;
	}
};
