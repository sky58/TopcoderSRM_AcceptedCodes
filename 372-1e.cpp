//SRM372DIV1-250(DIV2-500) RoadConstruction
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
string sol(string a){
	string ret;
	for(int i=1;i<a.size();i++) ret+=a[i];
	return ret;
}
class RoadConstruction{
	public:
	int RoadConstruction::getExitTime(vector <string> a){
		bool ka[55];int i,j,k,kei=0,n=a.size();
		memset(ka,false,sizeof(ka));
		for(i=0;i<n;i++) kei+=a[i].size();
		for(i=0;i<kei;i++){
			for(j=0;j<n;j++){
				if(ka[j] && a[j].size()>0) break;
			}
			if(j==n){
				for(k=n-1;k>=0;k--){
					if(a[k].size()>0) break;
				}
				j=k;
			}
			if(a[j][0]=='D') return i;
			a[j]=sol(a[j]);ka[j]=false;
			for(k=0;k<j;k++) ka[k]=true;
//			for(k=0;k<n;k++) cout<<a[k].size()<<'\n';cout<<'\n';
		}
	}
};
