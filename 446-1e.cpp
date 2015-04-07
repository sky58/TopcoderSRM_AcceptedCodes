//SRM446DIV1-250 CubeWalking
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
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class CubeWalking{
	public:
	string CubeWalking::finalPosition(string a){
		int x=301,y=301,i,mu=0;
		for(i=0;i<a.size();i++){
			if(a[i]=='W'){x+=dx[mu];y+=dy[mu];}
			if(a[i]=='L') mu=(mu+1)%4;
			if(a[i]=='R') mu=(mu+3)%4;
		}
		if(x%3==1 && y%3==1) return "GREEN";
		else if((x%3==0 || x%3==2) && (y%3==0 || y%3==2)) return "RED";
		else return "BLUE";
	}
};
