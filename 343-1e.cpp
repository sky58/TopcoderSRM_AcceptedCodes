//SRM343DIV1-250 CDPlayer
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
class CDPlayer{
	public:
	int CDPlayer::isRandom(vector <string> a,int n){
		string b;int i,j,k;
		for(i=0;i<a.size();i++) b+=a[i];
		
		for(i=0;i<n;i++){
			int memo[26];int f=0;memset(memo,0,sizeof(memo));
			for(j=0;j<i;j++){
				if(memo[(b[j]-'A')]==1) f=1;memo[(b[j]-'A')]=1;
			}
			for(j=0;j*n+i<b.size();j++){
				memset(memo,0,sizeof(memo));
				for(k=0;k<n && j*n+i+k<b.size();k++){
					if(memo[(b[j*n+i+k]-'A')]==1) f=1;memo[(b[j*n+i+k]-'A')]=1;
				}
			}
			if(f==0) return i;
		}
		return -1;
	}
};
