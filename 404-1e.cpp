//SRM404DIV1-250(DIV2-500) RevealTriangle
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
class RevealTriangle{
	public:
	vector <string> RevealTriangle::calcTriangle(vector <string> a){
		vector <int> b,c;vector <vector <int> > x;int n=a.size(),i,j;
	
		for(i=0;i<n;i++){
			b=c;
			for(j=0;j<n-i;j++){
				if(a[i][j]=='?') b.push_back(-1);
				else b.push_back(a[i][j]-'0');
			}
			x.push_back(b);
		}
	
		for(i=n-2;i>=0;i--){
			for(j=1;j<n-i;j++){
				if(x[i][j]==-1 && x[i][j-1]>-1){
					x[i][j]=(x[i+1][j-1]+10-x[i][j-1])%10;
					a[i][j]=(x[i][j]+'0');
				}
			}
			for(j=n-i-2;j>=0;j--){
				if(x[i][j]==-1 && x[i][j+1]>-1){
					x[i][j]=(x[i+1][j]+10-x[i][j+1])%10;
					a[i][j]=(x[i][j]+'0');
				}
			}
		}
		return a;
	}
};
