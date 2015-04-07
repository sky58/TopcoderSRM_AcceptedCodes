//SRM337DIV1-250 CardStraights
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
class CardStraights{
	public:
	int CardStraights::longestStraight(vector <int> a){
		int ze=0,n,i,j,k,out;vector <int> b;sort(a.begin(),a.end());
		for(i=0;i<a.size();i++){
			if(a[i]==0) ze++;
			else{
				if(i>0) if(a[i]==a[i-1]) continue;
				b.push_back(a[i]);
			}
		}
		sort(b.begin(),b.end());n=b.size();
		out=ze;if(b.size()>0) out++;
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			int f=0;
			for(k=i;k<j;k++) f+=b[k+1]-b[k]-1;
			if(f<=ze) out>?=(b[j]-b[i]+1+ze-f);
		}
		return out;
	}
};
