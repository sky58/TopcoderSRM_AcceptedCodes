//SRM440DIV1-1000 SquareFreeSets
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
int now[510][260];
int next[510][260];
int so[8]={2,3,5,7,11,13,17,19};
int s[510];
int mo=1000000007;
class SquareFreeSets{
	public:
	int SquareFreeSets::countPerfect(int n,int t){
		int i,j,k,l,out=0;
		memset(s,0,sizeof(s));
		for(i=0;i<8;i++) for(j=1;j*so[i]<=500;j++) s[j*so[i]]+=(1<<i);
		for(i=0;i<8;i++) for(j=1;j*so[i]*so[i]<=500;j++) s[j*so[i]*so[i]]=310;
		memset(now,0,sizeof(now));memset(next,0,sizeof(next));now[0][0]=1;next[0][0]=1;
		for(i=2;i<=n;i++){
			if(s[i]>300) continue;
			if(s[i]>0){
				for(j=0;j<t;j++) for(k=0;k<256;k++){
					if((s[i]&k)==0) next[j+1][k+s[i]]=(next[j+1][k+s[i]]+now[j][k])%mo;
				}
			}
			else{
			 for(l=1;l*i<=n;l++){
			 	if(s[l*i]>300) continue;
				for(j=0;j<t;j++) for(k=0;k<256;k++){
					if((s[i*l]&k)==0) next[j+1][k+s[i*l]]=(next[j+1][k+s[i*l]]+now[j][k])%mo;
				}
				s[l*i]=310;
			 }
			}
			memcpy(now,next,sizeof(next));
		}
		for(i=1;i<=t;i++) for(j=0;j<256;j++){
			out=(out+now[i][j])%mo;
		}
		return out;
	}
};
