//SRM417DIV1-500 CubeNets

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;

int mp[6][6];int f[6];

void kei(int x, int y, vector <int> kk){
	int d;vector <int> k;mp[x][y]=0;f[kk[0]]=1;
	if(x>0 && mp[x-1][y]==1){
		k=kk;d=k[1];k[1]=k[0];k[0]=k[3];k[3]=k[5];k[5]=d;kei(x-1,y,k);
	}
	if(x<5 && mp[x+1][y]==1){
		k=kk;d=k[0];k[0]=k[1];k[1]=k[5];k[5]=k[3];k[3]=d;kei(x+1,y,k);
	}
	if(y>0 && mp[x][y-1]==1){
		k=kk;d=k[0];k[0]=k[4];k[4]=k[5];k[5]=k[2];k[2]=d;kei(x,y-1,k);
	}
	if(y<5 && mp[x][y+1]==1){
		k=kk;d=k[4];k[4]=k[0];k[0]=k[2];k[2]=k[5];k[5]=d;kei(x,y+1,k);
	}
	return;
}

class CubeNets{
	public:
	string CubeNets::isCubeNet(std::vector <string> a){
		vector <int> k;int i, j, x, y;string out="";
		
		for(i=0;i<6;i++) f[i]=0;for(i=0;i<6;i++) for(j=0;j<6;j++) mp[i][j]=0;
		for(i=0;i<a.size();i++) for(j=0;j<a[0].size();j++){
			if(a[i][j]=='#'){
				mp[i][j]=1;x=i;y=j;
			}
		}
		for(i=0;i<6;i++) k.push_back(i);kei(x,y,k);
		for(i=0;i<6;i++) if(f[i]==0) return "NO";return "YES";
//		for(i=0;i<6;i++) if(f[i]==1) out+=(i+'0');return out;
	}
};
