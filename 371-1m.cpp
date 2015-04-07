//SRM371DIV1-500 ChessMatchup
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
int com(int a,int b){
	if(a>b) return 2;
	if(a<b) return 0;
	return 1;
}
class ChessMatchup{
	public:
	int ChessMatchup::maximumScore(vector <int> a,vector <int> b){
		int out=0,i,j,n=a.size();
		sort(a.begin(),a.end(),greater<int>());sort(b.begin(),b.end(),greater<int>());
		for(i=0;i<n;i++){
			int t=0;
			for(j=0;j+i<n;j++) t+=com(a[j],b[i+j]);
			for(j=0;j<i;j++) t+=com(a[n-1-j],b[j]);
			out>?=t;
		}
		return out;
	}
};
