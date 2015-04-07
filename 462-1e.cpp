//SRM462DIV1-250 AgeEncoding
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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
class AgeEncoding{
	public:
	double AgeEncoding::getRadix(int a,string b){
		int n=b.size(),t=0,i,j;double x=0.0,y=1e10;
		for(i=0;i<n;i++){
			if(b[i]=='1') t++;
		}
		if(t==0) return -1.0;
		if(t==1 && b[n-1]=='1'){
			if(a==1) return -2.0;return -1.0;
		}
		if(t>1 && b[n-1]=='1' && a==1) return -1.0;
		for(i=0;i<100;i++){
			double z=(x+y)/2,w=0.0;
			for(j=0;j<n;j++){
				w*=z;if(b[j]=='1') w+=1.0;
			}
			if(w>1.0*a) y=z;else x=z;
		}
		return (x+y)/2;
	}
};
