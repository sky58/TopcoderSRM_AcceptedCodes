//SRM429DIV1-1000 SpecificPolyominoCovering
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
int ax[6]={0,0,1,1,1,1};
int ay[6]={0,3,0,1,2,3};
int bx[2]={0,0};int by[2]={0,1};
int n,m;
bool okea(int x,int y,vector <string> a){
	for(int i=0;i<6;i++){
		int px=x+ax[i],py=y+ay[i];
		if(px>=n || py>=m) return false;
		if(a[px][py]!='X') return false;
	}
	return true;
}
bool okeb(int x,int y,vector <string> a){
	for(int i=0;i<2;i++){
		int px=x+bx[i],py=y+by[i];
		if(px>=n || py>=m) return false;
		if(a[px][py]!='X') return false;
	}
	return true;
}
bool ka(vector <string> str){
	int i,j,k;
	for(i=0;i<n;i++) for(j=0;j<m;j++){
		if(str[i][j]!='X') continue;
		if(okeb(i,j,str)){
			for(k=0;k<2;k++) str[i+bx[k]][j+by[k]]='B';
			continue;
		}
		if(okea(i,j,str)){
			for(k=0;k<6;k++) str[i+ax[k]][j+ay[k]]='A';
			continue;
		}
		return false;
	}
	return true;
}
class SpecificPolyominoCovering{
	public:
	vector <string> SpecificPolyominoCovering::findCovering(vector <string> a){
		vector <string> out;int i,j,k;n=a.size();m=a[0].size();
		if(!ka(a)) return out;
		
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]!='X') continue;
			if(okea(i,j,a)){
				for(k=0;k<6;k++) a[i+ax[k]][j+ay[k]]='A';
				if(!ka(a)){
					for(k=0;k<6;k++) a[i+ax[k]][j+ay[k]]='X';
					for(k=0;k<2;k++) a[i+bx[k]][j+by[k]]='B';
				}
			}
			else for(k=0;k<2;k++) a[i+bx[k]][j+by[k]]='B';
		}
		return a;
	}
};
