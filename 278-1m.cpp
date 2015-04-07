//SRM278DIV1-450 OneMorePoint
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
map<int,int> mex,mey;
int x1[55];int y5[55];int x2[55];int y2[55];
bool sumi[115][115];
class OneMorePoint{
	public:
	string OneMorePoint::interiorPoint(vector <string> a){
		vector <int> xa,xb,ya,yb;int i,j,k,n=a.size(),f;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++){
			istringstream sin(a[i]);sin>>x1[i]>>y5[i]>>x2[i]>>y2[i];
			xa.pb(x1[i]);xa.pb(x2[i]);ya.pb(y5[i]);ya.pb(y2[i]);
		}
		
		sort(xa.begin(),xa.end());
		xb.pb(xa[0]);for(i=1;i<xa.size();i++){if(xa[i]!=xa[i-1]) xb.pb(xa[i]);}
		for(i=0;i<xb.size();i++) mex[xb[i]]=i;
		
		sort(ya.begin(),ya.end());
		yb.pb(ya[0]);for(i=1;i<ya.size();i++){if(ya[i]!=ya[i-1]) yb.pb(ya[i]);}
		for(i=0;i<yb.size();i++) mey[yb[i]]=i;
		
		for(i=0;i<n;i++) for(j=mex[x1[i]];j<mex[x2[i]];j++) for(k=mey[y5[i]];k<mey[y2[i]];k++) sumi[j][k]=true;
		for(i=0;i<110;i++) for(j=0;j<110;j++){
			if(sumi[i][j]) continue;
			f=0;
			for(k=i-1;k>=0;k--){if(sumi[k][j]) f=1;}
			if(f==0) continue;
			
			f=0;
			for(k=j-1;k>=0;k--){if(sumi[i][k]) f=1;}
			if(f==0) continue;
			
			f=0;
			for(k=i+1;k<108;k++){if(sumi[k][j]) f=1;}
			if(f==0) continue;
			
			f=0;
			for(k=j+1;k<108;k++){if(sumi[i][k]) f=1;}
			if(f==0) continue;
			
			return "YES";
		}
		return "NO";
	}
};
