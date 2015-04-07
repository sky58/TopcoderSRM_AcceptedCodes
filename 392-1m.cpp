//SRM392DIV1-500 RoundAboutCircle

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
int memo[210000];bool sumi[210000];
int dig(int a){
	int ret=0;
	while(a>0){
		ret+=a%10;a/=10;
	}
	return ret;
}

class RoundAboutCircle{
	public:
	int RoundAboutCircle::maxScore(int n){
		int i,j,t,out=0;
		memset(memo,-1,sizeof(memo));memset(sumi,false,sizeof(sumi));
		if(n<10){memo[n]=1;sumi[n]=true;}
		for(i=1;i<=n;i++){
			if(sumi[i]) continue;
			t=i;vector <int> c;
			while(1){
				sumi[t]=true;c.push_back(t);t=(t+dig(t)-1)%n+1;
				if(sumi[t]) break;
			}
			if(memo[t]>-1){
				for(j=0;j<c.size();j++) memo[c[j]]=memo[t]+c.size()-j;
			}
			else{
				int lo;
				for(lo=1;lo<=c.size();lo++) if(t==c[c.size()-lo]) break;
				if(lo==c.size()) for(j=0;j<lo;j++) memo[c[j]]=lo;
				else{
					for(j=c.size()-1;j>=c.size()-lo;j--) memo[c[j]]=lo;
					for(j=1;j<=c.size()-lo;j++) memo[c[c.size()-lo-j]]=lo+j;
				}
			}
		}
		for(i=1;i<=n;i++) out=max(out,memo[i]);return out;
	}
};
