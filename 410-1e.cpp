//SRM410DIV1-250 AddElectricalWires

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
int tai[35];int n;vector <string> A;
void kei(int a,int b){
	int i;
	if(tai[b]>-1) return;tai[b]=a;
	for(i=0;i<n;i++) if(A[b][i]=='1') kei(a,i);
	return;
}
	
class AddElectricalWires{
	public:
	int AddElectricalWires::maxNewWires(vector <string> a,vector <int> b){
		int i,j,k,f,maxi,max=0,out=0;vector <int> c;vector <vector <int> > graph;
		n=a.size();A=a;
		for(i=0;i<n;i++) tai[i]=-1;for(i=0;i<b.size();i++) graph.push_back(c);
		
		for(i=0;i<b.size();i++) kei(i,b[i]);//return tai[3];
		for(i=0;i<n;i++) if(tai[i]>-1) graph[tai[i]].push_back(i);//return graph[1].size();
		for(i=0;i<b.size();i++){
			if(graph[i].size()>max){
				max=graph[i].size();maxi=i;
			}
		}
//		return maxi;
		for(i=0;i<n;i++) if(tai[i]==-1) graph[maxi].push_back(i);
		for(i=0;i<b.size();i++){
			f=0;
			for(j=0;j<graph[i].size();j++) for(k=j+1;k<graph[i].size();k++) if(a[graph[i][j]][graph[i][k]]=='1') f++;
			out+=graph[i].size()*(graph[i].size()-1)/2;out-=f;
		}
		return out;
	}
};
