//SRM343DIV1-1000 RefactorableNumber
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
int dp[4000000];
class RefactorableNumber{
	public:
	int RefactorableNumber::count(int a,int b){
		vector <int> sosuu;int i, j, f,k,out=0;
		sosuu.push_back(2);memset(dp,0,sizeof(dp));dp[1]=1;
		for(i=3;i<=2000010;i++){
			f=0;
			for(j=0;sosuu[j]*sosuu[j]<=i;j++) if(i%sosuu[j]==0){f=1;break;}
			if(f==0){sosuu.push_back(i);}
		}
//		return sosuu.size();
		for(i=0;i<sosuu.size();i++){
			for(j=1;j<=2000000/sosuu[i];j++){
				if(dp[j]==0) continue;
				if(j%sosuu[i]==0) continue;
				int t=1;k=2;
				while(1){
					t*=sosuu[i];dp[j*t]=dp[j]*k;k++;
//					printf("dp[%d]=%d",j*t,dp[j*t]);
					if(2000000/sosuu[i]<t*j) break;
				}
			}
		}
//		return dp[2000000];
		for(i=a;i<=b;i++){
			if(i%dp[i]==0) out++;
		}
		return out;
	}
};
