//SRM360DIV1-250 SumOfSelectedCells
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
class SumOfSelectedCells{
	public:
	string SumOfSelectedCells::hypothesis(vector <string> a){
		vector <vector <int> > b;
		int i,j,n=a.size();
		for(i=0;i<n;i++){
			vector <int> c;
			istringstream sin(a[i]);
			for(int v;sin>>v;c.push_back(v));
			b.push_back(c);
		}
		int m=b[0].size();
		if(n==1){
			for(i=0;i<m-1;i++) if(b[0][i]!=b[0][i+1]) return "INCORRECT";return "CORRECT";
		}
		if(m==1){
			for(i=0;i<n-1;i++) if(b[i][0]!=b[i+1][0]) return "INCORRECT";return "CORRECT";
		}
		if(m>n){
			for(i=0;i<n;i++){
				for(j=1;j<m;j++) if(b[i][0]!=b[i][j]) return "INCORRECT";
			}
			return "CORRECT";
		}
		for(i=0;i<m-1;i++){
			for(j=0;j<n-1;j++){
				if(b[j][i]-b[j][i+1]!=b[j+1][i]-b[j+1][i+1]) return "INCORRECT";
			}
		}
		if(m<n){
			for(i=0;i<n-1;i++) if(b[i][0]!=b[i+1][0]) return "INCORRECT";
		}
		return "CORRECT";
	}
};
