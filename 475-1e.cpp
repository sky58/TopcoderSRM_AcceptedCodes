//SRM475DIV1-300(DIV2-550) RabbitStepping
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
class RabbitStepping{
	public:
	double RabbitStepping::getExpected(string a,int b){
		int n=a.size(),i;double out1=0.0,out2=0.0;string c="";
		for(i=0;i<b;i++) c+='a';for(i=0;i<n-b;i++) c+='b';
		while(1){
			out2+=1.0;int t=0,s=0;
			for(i=0;i<n;i++){
				if(c[i]=='a'){
					if(i%2==0) t++;else s++;
				}
			}
			out1+=1.0*(t%2+s%2);
			if(!next_permutation(c.begin(),c.end())) break;
		}
		return out1/out2;
	}
};
