//SRM340DIV1-250 ProblemsToSolve
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
int ma[60][60][1100];
class ProblemsToSolve{
	public:
	int ProblemsToSolve::minNumber(vector <int> a,int b){
		int i,j,k,n=a.size(),out=n;
		
		for(i=0;i<60;i++) for(j=0;j<60;j++) for(k=0;k<1100;k++) ma[i][j][k]=11000;
		ma[0][1][a[0]]=a[0];
//		return out;
		for(i=0;i<n-1;i++) for(j=0;j<n;j++) for(k=0;k<1001;k++){
			if(ma[i][j][k]>10000) continue;
//			printf("%d %d %d %d\n",i,j,k,ma[i][j][k]);
			ma[i+1][j+1][max(k,a[i+1])]<?=min(a[i+1],ma[i][j][k]);
			if(i<n-2) ma[i+2][j+1][max(k,a[i+2])]<?=min(ma[i][j][k],a[i+2]);
		}
//		cout<<ma[4][3][5];
		for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<1001;k++){
			if(k-ma[i][j][k]>=b) out<?=j;
		}
		return out;
	}
};
