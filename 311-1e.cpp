//SRM311DIV1-300 MatrixTransforming
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
int ma[55][55];
int dx[9]={-1,-1,-1,0,0,0,1,1,1},dy[9]={-1,0,1,-1,0,1,-1,0,1};
class MatrixTransforming{
	public:
	int MatrixTransforming::minPushes(vector <string> a,vector <string> b){
		int i,j,k,m=a[0].size(),n=a.size(),out=0;
		if(m<3 || n<3){if(a==b) return 0;return -1;}
/*		for(i=0;i<n;i++) for(i=0;i<m;i++){
			if(i==0 || i==n-1 || j==0 || j==m-1) ma[i][j]=0;else ma[i][j]=-1;
		}
*/		memset(ma,0,sizeof(ma));
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(i<n-2 && j<m-2){
				int t=0;
				for(k=0;k<8;k++){
					int x=i+dx[k],y=j+dy[k];
					if(x>=0 && x<n && y>=0 && y<m) t+=ma[x][y];
				}
				if((t+(a[i][j]-'0')+(b[i][j]-'0'))%2!=0){ma[i+1][j+1]=1;out++;}
			}
			else{
				int t=0;
				for(k=0;k<9;k++){
					int x=i+dx[k],y=j+dy[k];
					if(x>=0 && x<n && y>=0 && y<m) t+=ma[x][y];
				}
				if((t+(a[i][j]-'0')+(b[i][j]-'0'))%2!=0) return -1;
			}
		}
		return out;
	}
};
