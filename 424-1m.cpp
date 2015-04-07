//SRM424DIV1-600 StrengthOrIntellect

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
class StrengthOrIntellect{
	public:
	int StrengthOrIntellect::numberOfMissions(std::vector <int> st, std::vector <int> in, std::vector <int> po){
		int i, j, k, out=0, ten, point;
		bool dp[1010][1010];
		for(i=0;i<1010;i++) for(j=0;j<1010;j++) dp[i][j]=false;
		dp[1][1]=true;
		for(i=1;i<=1000;i++) for(j=1;j<=1000;j++){
			if(!dp[i][j]) continue;
			ten=0, point=2;
			for(k=0;k<st.size();k++) if(st[k]<=i || in[k]<=j){
				ten++;point+=po[k];
			}
			out=max(out,ten);point-=(i+j);
			for(k=0;k<=point;k++) dp[min(i+k,1000)][min(j+point-k,1000)]=true;
		}
		return out;
	}
};
