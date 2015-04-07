//SRM386DIV1-250 CandidateKeys
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
bool dp[1100];
class CandidateKeys{
	public:
	vector <int> CandidateKeys::getKeys(vector <string> a){
		vector <int> out;int i,j,k,max=0,min=20,m=a.size(),n=a[0].size();
		for(i=0;i<1100;i++) dp[i]=true;
		for(i=0;i<(1<<n);i++){
			string b[55];
			for(j=0;j<m;j++) for(k=0;k<n;k++){
				if(i&(1<<k)) b[j]+=a[j][k];
			}
			for(j=0;j<m-1;j++) for(k=j+1;k<m;k++){
				if(b[j]==b[k]) dp[i]=false;
			}
		}
		for(i=0;i<(1<<n);i++){
			if(dp[i]){
				min<?=__builtin_popcount(i);
				max>?=__builtin_popcount(i);
				for(j=i+1;j<(1<<n);j++){
					if((i&j)==i) dp[j]=false;
				}
			}
		}
		if(max==0) return out;
		out.push_back(min);out.push_back(max);
		return out;
	}
};
