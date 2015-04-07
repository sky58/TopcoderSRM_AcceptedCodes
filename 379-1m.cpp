//SRM379DIV1-500 FillBox
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
#include<queue>
#include<deque>
using namespace std;
typedef long long lint;
class FillBox{
	public:
	int FillBox::minCubes(int x,int y,int z,vector <int> a){
		int nx=0,ny=0,nz=0,out=0,i,j;
		for(i=a.size()-1;i>=0;i--){
			int t=(1<<i),px=x/t*t,py=y/t*t,pz=z/t*t;
			lint hi=((lint)px*py*pz-(lint)nx*ny*nz)/t/t/t;
			if(hi>1000000000) return -1;
//			cout<<i<<' '<<px<<' '<<py<<' '<<pz<<' '<<out<<' '<<hi<<'\n';
			for(j=i;j>=0;j--){
				lint aru=min(hi,(lint)a[j]);
				out+=(int)aru;hi-=aru;a[j]-=(int)aru;
				hi*=8;if(j==0 && hi>0) return -1;
			}
			nx=px;ny=py;nz=pz;
		}
		return out;
	}
};
