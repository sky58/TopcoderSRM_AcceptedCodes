//SRM328DIV1-250 LightsCube
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
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int cu[45][45][45],next[45][45][45];
class LightsCube{
	public:
	vector <int> LightsCube::count(int n,vector <string> a){
		vector <int> out;int i,j,k,l,m;
		for(i=0;i<a.size();i++) out.push_back(0);
//		memset(cu,-1,sizeof(cu));
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++){cu[i][j][k]=200;next[i][j][k]=200;}
		for(i=0;i<a.size();i++){
			int x,y,z;istringstream sin(a[i]);
			sin>>x>>y>>z;cu[x][y][z]=i;next[x][y][z]=i;
		}
		for(i=0;i<150;i++){
//			memcpy(next,cu,sizeof(cu));
			for(j=0;j<n;j++) for(k=0;k<n;k++) for(l=0;l<n;l++){
				if(next[j][k][l]<200) continue;
				int s=200;
				for(m=0;m<6;m++){
					int x=j+dx[m],y=k+dy[m],z=dz[m]+l;
					if(x<0 || x>=n || y<0 || y>=n || z<0 || z>=n) continue;
					s<?=cu[x][y][z];
				}
				next[j][k][l]=s;
			}
//			memcpy(cu,next,sizeof(next));
			for(l=0;l<n;l++) for(j=0;j<n;j++) for(k=0;k<n;k++){
				cu[l][j][k]=next[l][j][k];
//				cout<<cu[l][j][k]<<'\n';
			}
//			cout<<i<<"a\n";
		}
//		cout<<"a\n";
//		cout<<out.size()<<"a\n";
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) out[cu[i][j][k]]++;
		return out;
	}
};
