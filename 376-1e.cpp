//SRM376DIV1-250 Trainyard
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
#define pb push_back
class Trainyard{
	public:
	int Trainyard::reachableSquares(vector <string> a,int b){
		vector <vector <int> > ed;vector <int> now,next,cl;
		int h=a.size(),w=a[0].size(),i,j,k,out=0;
		bool sumi[120];memset(sumi,false,sizeof(sumi));
		for(i=0;i<h*w;i++) ed.pb(cl);
		for(i=0;i<h;i++) for(j=0;j<w;j++){
			if(a[i][j]=='S'){now.pb(i*w+j);sumi[i*w+j]=true;}
			if(j<w-1 && (a[i][j]=='S' || a[i][j]=='-' || a[i][j]=='+')){
				if(a[i][j+1]=='S' || a[i][j+1]=='-' || a[i][j+1]=='+'){
					ed[i*w+j].pb(i*w+j+1);ed[i*w+j+1].pb(i*w+j);
				}
			}
			if(i<h-1 && (a[i][j]=='S' || a[i][j]=='|' || a[i][j]=='+')){
				if(a[i+1][j]=='S' || a[i+1][j]=='|' || a[i+1][j]=='+'){
					ed[i*w+j].pb(i*w+j+w);ed[i*w+j+w].pb(i*w+j);
				}
			}
		}
		for(i=0;i<b;i++){
			for(j=0;j<now.size();j++){
				int t=now[j];
				for(k=0;k<ed[t].size();k++){
					if(!sumi[ed[t][k]]){next.pb(ed[t][k]);sumi[ed[t][k]]=true;}
				}
			}
			now=next;next=cl;
		}
		for(i=0;i<110;i++){
			if(sumi[i]) out++;
		}
		return out;
	}
};
