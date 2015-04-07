//SRM292DIV1-1000 LongBlob
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
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int dis[630][630];
class LongBlob{
	public:
	double LongBlob::maxLength(vector <string> a){
		int i,j,k,n=a.size(),m=a[0].size(),l;double out=0.0;
		memset(dis,10000,sizeof(dis));
		for(i=0;i<630;i++) dis[i][i]=0;
		for(i=0;i<n;i++) for(j=0;j<m;j++) for(k=0;k<4;k++){
			int x=i+dx[k],y=j+dy[k];
			if(x<0 || x>=n || y<0 || y>=m) continue;
			dis[x*m+y][i*m+j]=(a[i][j]-'0')+(a[x][y]-'0');
		}
		for(k=0;k<m*n;k++) for(i=0;i<m*n;i++) for(j=0;j<m*n;j++) dis[i][j]<?=dis[i][k]+dis[k][j];
		for(i=0;i<n;i++) for(j=0;j<m;j++) for(k=0;k<n;k++) for(l=0;l<m;l++){
			if(dis[i*m+j][k*m+l]+(a[i][j]-'0')+(a[k][l]-'0')<=8) out>?=sqrt(1.0*(k-i)*(k-i)+1.0*(l-j)*(l-j));
		}
		return out;
	}
};
