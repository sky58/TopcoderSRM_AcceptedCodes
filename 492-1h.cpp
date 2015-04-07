//SRM492DIV1-1000 TimeTravellingGogo
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
typedef pair<lint,int> pint;
lint inf=1000000000000000LL;
lint gr[25][25];
lint zi[25][1000],za[25][1000],ka[25][1000];int v;
priority_queue<pint> q;
void pus(lint a,int b,int c){
	if(ka[b][c]<1) return;if(za[b][c]<1 && za[b][c]>a) return;
	za[b][c]=a;q.push(mp(a,b*v+c));return;
}
class TimeTravellingGogo{
	public:
	long long TimeTravellingGogo::determineTime(int n,vector <int> a,vector <int> b,vector <string> c,int d){
		int m=a.size(),i,j,k;v=2*n*m+m*2;string s="",s1;char c1,c2;lint x,y,z;
		for(i=0;i<c.size();i++) s+=c[i];
		istringstream sin(s);
		for(i=0;i<25;i++) for(j=0;j<25;j++) gr[i][j]=inf;for(i=0;i<25;i++) gr[i][i]=0;
		while(sin>>s1){istringstream sin2(s1);sin2>>x>>c1>>y>>c2>>z;gr[x][y]<?=z;gr[y][x]<?=z;}
		for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) gr[i][j]<?=gr[i][k]+gr[k][j];
		for(i=0;i<25;i++) for(j=0;j<1000;j++){zi[i][j]=inf;za[i][j]=ka[i][j]=1;}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) zi[i][j]=a[j];
			for(j=0;j<n;j++) for(k=0;k<m;k++){if(a[k]<=b[k]-gr[i][j]) zi[i][m+j*m+k]=b[k]-gr[i][j];}
			for(j=0;j<m;j++) zi[i][j+v/2]=b[j];
			for(j=0;j<n;j++) for(k=0;k<m;k++){if(a[k]+gr[i][j]<=b[k]) zi[i][m+v/2+j*m+k]=a[k]+gr[i][j];}
		}
		for(i=0;i<v/2;i++){if(zi[0][i]<inf) q.push(mp(-zi[0][i],i));}
		while(!q.empty()){
			pint e=q.top();q.pop();x=e.se/v;y=e.se%v;z=e.fi;if(x==n-1) return -z;if(ka[x][y]<1) continue;
//			cout<<zi[x][y]<<"m "<<x<<' '<<y<<' '<<-z<<endl;
			ka[x][y]=z;
			if(y<m){
				for(i=0;i<n;i++){
					if(zi[i][m+v/2+x*m+y]<inf) pus(z-gr[x][i],i,m+v/2+x*m+y);
				}
			}
			else if(y<v/2){
				int s=(y-m)/m,t=(y-m)%m;
				if(zi[x][y]<inf) pus(z-gr[x][s],s,v/2+t);
			}
			else{
				for(i=0;i<v/2;i++){
					if(zi[x][i]>=inf) continue;
					if(zi[x][i]>=zi[x][y]) pus(z-(zi[x][i]-zi[x][y]),x,i);
					else pus(z-(zi[x][y]-zi[x][i])-d,x,i);
				}
			}
		}
		return -1;
	}
};
